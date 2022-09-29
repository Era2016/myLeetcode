#include "dict.h"

#include <stdlib.h>

static void _dictReset(dictht *ht) {
    ht->table = NULL;
    ht->size = 0;
    ht->sizemask = 0;
    ht->used = 0;
}

int _dictInit(dict *d, dictType *type, void *privDataPtr) {

    _dictReset(&d->ht[0]);
    _dictReset(&d->ht[1]);
    d->type = type;
    d->privdata = privDataPtr;
    d->rehashidx = -1;
    d->iterators = 0;

    return 1;
}


dict *dictCreate(dictType *type, void *privDataPtr) {
    dict *d = (dict*) malloc(sizeof(struct dict));

    _dictInit(d, type, privDataPtr);
    return d;
}

int _dictClear(dict *d, dictht *ht, void(callback)(void *)) {
    unsigned long i;

    for (i = 0; i < ht->size && ht->used > 0; i ++) {
        dictEntry *he, *nextHe;

        if (callback && (i & 65535) == 0) callback(d->privdata);

        if ((he = ht->table[i]) == NULL) continue;
        while (he) {
            nextHe = he->next;
            free(he);
            //dictFreeKey(d, he); type function
            //dictFreeVal(d, he); type function
            ht->used --;
            he = nextHe;
        }
    }

    free(ht->table);
    _dictReset(ht);
    
    return 1;
}

void dictRelease(dict *d) {
    _dictClear(d, &d->ht[0], NULL);
    _dictClear(d, &d->ht[1], NULL);

    free(d);
}

int dictAdd(dict *d, void *key, void *val) {
    dictEntry *entry = dictAddRaw(d, key, NULL);

    if (!entry) return -1;
    entry->v.val = val; //dictSetVal(d, entry, val);
    return 1;
}

dictEntry *dictAddRaw(dict *d, void *key, dictEntry **existing) {
    long index;
    dictEntry *entry;
    dictht *ht;

    //if (dictIsRehashing(d)) _dictRehashStep(d);
    uint64_t (*dictHashKey)(const void *key) = d->type->hashFunction;
    if ((index = _dictKeyIndex(d, key, dictHashKey(key), existing)) == -1)
        return NULL;

    ht = (d->rehashidx != -1)? &d->ht[1]: &d->ht[0];
    entry = (dictEntry*) malloc(sizeof(*entry));
    entry->next = ht->table[index];
    ht->table[index] = entry;
    ht->used ++;

    entry->key = key; //dictSetKey(d, entry, key);
    return entry;
}

static dictEntry *dictGenericDelete(dict *d, const void *key, int nofree) {
    uint64_t h, idx;
    dictEntry *he, *prevHe;
    int table;

    if (d->ht[0].used + d->ht[1].used == 0) return NULL;

    //if (d->rehashidx != -1) _dictRehashStep(d);
    uint64_t (*dictHashKey) (const void *key) = d->type->hashFunction;
    h = dictHashKey(key);

    for (table = 0; table <= 1; table++) {
        idx = h & d->ht[table].sizemask;
        he = d->ht[table].table[idx];
        prevHe = NULL;

        while (he) {
            if (key == he->key) {
                if (prevHe)
                    prevHe->next = he->next;
                else 
                    d->ht[table].table[idx] = he->next;
                if (!nofree) {
                    //dictFreeKey(d, he);
                    //dictFreeVal(d, he);
                    free(he); 
                }

                d->ht[table].used --;
                return he;
            } 
            prevHe = he;
            he = he->next;
        }
        if (!(d->rehashidx != -1)) break;
    }

    return NULL;
}

int dictDelete(dict *ht, const void *key) {
    return dictGenericDelete(ht, key, 0) ?1 :-1;
}

static long _dictKeyIndex(dict *d, const void *key, uint64_t hash, dictEntry **existing) {
    unsigned long idx, table;
    dictEntry *he;

    //if (_dictExpandIfNeeded(d) == -1)
    //    return -1;

    for (table = 0; table <= 1; table++) {
        idx = hash & d->ht[table].sizemask;
        he = d->ht[table].table[idx];
        while (he) {
            if (key == he->key) {
                if (existing) *existing = he;
                return -1;
            }
            he = he->next;
        }
        if (!(d->rehashidx!=-1)) break;
    }
    return idx;
}

dictEntry *dictFind(dict *d, const void *key) {
    dictEntry *he;
    uint64_t h, idx, table;

    if (d->ht[0].used + d->ht[1].used == 0) return NULL;
    //if (d->rehashidx != -1) _dictRehashStep(d);

    uint64_t (*dictHashKey)(const void *key) = d->type->hashFunction;
    h = dictHashKey(key);
    for (table = 0; table <= 1; table ++) {
        idx = h & d->ht[table].sizemask;
        he = d->ht[table].table[idx];
        while (he) {
            if (key == he->key) return he;
            he = he->next;
        }

        if (!(d->rehashidx != -1)) return NULL;
    }

    return NULL;
}

static unsigned long rev(unsigned long v) {
    unsigned long s = 8 * sizeof(v);
    unsigned long mask = ~0;
    while ((s >> 1) > 0) {
        mask ^= (mask << s);
        v = ((v >> s) & mask) | ((v << s) & ~mask);
    }
    return v;
}

unsigned long dictScan(dict *d,
        unsigned long v,
        dictScanFunction *fn,
        dictScanBucketFunction *bucketfn,
        void *privdata) {
    
    dictht *t0, *t1;
    const dictEntry *de, *next;
    unsigned long m0, m1;

    if (d->ht[0].used + d->ht[1].used == 0) return 0;

    if (!(d->rehashidx != -1)) {
        t0 = &(d->ht[0]);
        m0 = t0->sizemask;

        if (bucketfn) bucketfn(privdata, &t0->table[v&m0]);
        de = t0->table[v&m0];
        while (de) {
            next = de->next;
            fn(privdata, de);
            de = next;
        }

        v |= ~m0;

        v = rev(v);
        v++;
        v = rev(v);
    } else {
        t0 = &d->ht[0];
        t1 = &d->ht[1];

        if (t0->size > t1->size) {
            t0 = &d->ht[1];
            t1 = &d->ht[0];
        }

        m0 = t0->sizemask;
        m1 = t1->sizemask;

        if (bucketfn) bucketfn(privdata, &t0->table[v&m0]);
        de = t0->table[v&m0];
        while (de) {
            next = de->next;
            fn(privdata, de);
            de = next;
        }

        do {
            if (bucketfn) bucketfn(privdata, &t1->table[v&m1]);
            de = t1->table[v&m1];
            while (de) {
                next = de->next;
                fn(privdata, de);
                de = next;
            }

            v |= ~m1;
            v = rev(v);
            v++;
            v = rev(v);

        } while (v &  (m0 ^ m1));
    }
    
    return v;
}

//static unsigned long rev(unsigned long v) {
//    unsigned long s = 8 * sizeof(v);
//    unsigned long mask = ~0;
//    while ((s >> 1) > 0) {
//        mask ^= (mask << s);
//        v = ((v >> s) & mask) | ((v << s) & ~mask);
//    }
//    return v;
//}
