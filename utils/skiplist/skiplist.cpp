#include <stdlib.h>
#include <string.h>
#include "./zskiplist.h"

zskiplistNode *zslCreateNode(int level, double score, sds ele) {
    zskiplistNode *zn = 
        (zskiplistNode*) malloc(sizeof(*zn) + level*sizeof(struct zskiplistLevel));    
    zn->score = score;
    zn->ele = ele;
    return zn;
}

void zslFreeNode(zskiplistNode *node) {
    free(node->ele);
    free(node);
}

void zslDeleteNode(zskiplist *zsl, zskiplistNode *x, zskiplistNode **update) {
    int i;
    for (i = 0; i < zsl->level; i ++) {
        if (update[i]->level[i].forward == x) {
            update[i]->level[i].span += x->level[i].span - 1;
            update[i]->level[i].forward = x->level[i].forward;
        } else {
            update[i]->level[i].span -= 1;
        }
    }
    if (x->level[0].forward) {
        x->level[0].forward->backward = x->backward;
    } else {
        zsl->tail = x->backward;
    }

    while (zsl->level > 1 && zsl->header->level[zsl->level-1].forward == nullptr) {
        zsl->level --;
    }
    zsl->length --;
}

int zslRandomLevel(void) {
    int level = 1;
    while ((random()&0xFFFF) < (ZSKIPLIST_P * 0xFFFF))
        level += 1;
    return (level<ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
}

zskiplist *zskCreate(void) {
    int j;
    zskiplist *zsl;

    zsl = (zskiplist*) malloc(sizeof(*zsl));
    zsl->level = 1;
    zsl->length = 0;
    zsl->header = zslCreateNode(ZSKIPLIST_MAXLEVEL, 0, nullptr); 
    for (j = 0; j < ZSKIPLIST_MAXLEVEL; j ++) {
        zsl->header->level[j].forward = nullptr;
        zsl->header->level[j].span = 0;
    }
    zsl->header->backward = nullptr;
    zsl->tail = nullptr;
    return zsl;
}

void zslFree(zskiplist *zsl) {
    zskiplistNode *node = zsl->header->level[0].forward, *next;

    free(zsl->header);
    while (node) {
        next = node->level[0].forward;
        zslFreeNode(node);
        node = next;
    }
    free(zsl);
}

zskiplistNode *zslInsert(zskiplist *zsl, double score, sds ele) {
    zskiplistNode *update[ZSKIPLIST_MAXLEVEL], *x;
    unsigned int rank[ZSKIPLIST_MAXLEVEL];

    int i, level;
    x = zsl->header;
    for (i = zsl->level-1; i >= 0; i --) {
        rank[i] = i == zsl->level-1 ? 0: rank[i+1];
        while (x->level[i].forward && 
                x->level[i].forward->score < score ||
                (x->level[i].forward->score == score && 
                 strcmp(x->level[i].forward->ele, ele) < 0)) {
            rank[i] += x->level[i].span;
            x = x->level[i].forward;
        }

        update[i] = x;
    }

    level = zslRandomLevel();
    if (level > zsl->level) {
        for (i = zsl->level; i < level; i ++) {
            rank[i] = 0;
            update[i] = zsl->header;
            update[i]->level[i].span = zsl->length;
        }
        zsl->level = level;
    }
    x = zslCreateNode(level, score, ele);
    for (i = 0; i < level; i ++) {
        x->level[i].forward = update[i]->level[i].forward;
        update[i]->level[i].forward = x;

        x->level[i].span = update[i]->level[i].span - (rank[0]-rank[i]);
        update[i]->level[i].span = rank[0]-rank[i]+1;
    }

    for (i = level; i < zsl->level; i ++) {
        update[i]->level[i].span ++;
    }

    x->backward = (update[0] == zsl->header)? nullptr: update[0];
    if (x->level[0].forward) {
        x->level[0].forward->backward = x;
    } else {
        zsl->tail = x;
    }

    zsl->length ++;
    return x;
}
