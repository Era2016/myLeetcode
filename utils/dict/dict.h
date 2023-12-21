#include <stdint.h>

typedef struct dictEntry {
    void *key;
    union {
        void *val;
        uint64_t u64;
        int64_t s64;
        double d;
    } v;
    struct dictEntry *next;
} dictEntry;

typedef struct dictType {
    uint64_t (*hashFunction) (const void *key);
    void *(*keyDup) (void *privdata, const void *key);
    void *(*valDup) (void *privdata, const void *obj);
    int (*keyCompare) (void *privdata, const void *key1, const void *key2);
    void (*keyDestructor) (void *privdata, void *key);
    void (*valDestructor) (void *privdata, void *obj);
} dictType;

typedef struct dictht {
    dictEntry **table;
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
} dictht;

typedef struct dict {
    dictType *type;
    void *privdata;
    dictht ht[2];
    long rehashidx;
    unsigned long iterators;
} dict;

typedef void (dictScanFunction) (void *privdata, const dictEntry *de);
typedef void (dictScanBucketFunction) (void *privdata, dictEntry **bucketref);

int _dictInit(dict *d, dictType *type, void *privDataPtr);
dict *dictCreate(dictType *type, void *privDataPtr);
static void _dictReset(dictht *ht);

int _dictClear(dict *d, dictht *ht, void(callback)(void *));
void dictRelease(dict *d);

int dictDelete(dict *ht, const void *key);
static dictEntry *dictGenericDelete(dict *d, const void *key, int nofree);

int dictAdd(dict *d, void *key, void *val);
dictEntry *dictAddRaw(dict *d, void *key, dictEntry **existing);

dictEntry *dictFind(dict *d, const void *key);
static long _dictKeyIndex(dict *d, const void *key, uint64_t hash, dictEntry **existing);

//static unsigned long rev(unsigned long v);
unsigned long dictScan(dict *d, unsigned long v, 
        dictScanFunction *fn,
        dictScanBucketFunction *bucketfn,
        void *privdata);
