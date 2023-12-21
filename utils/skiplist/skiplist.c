#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include "skiplist.h"

skiplistNode *slCreateNode(int level, double score, sds ele) {

    skiplistNode *sn = (skiplistNode*) malloc(sizeof(*sn) + level*sizeof(struct skiplistLevel));

    sn->score = score;
    sn->ele = ele;
    return sn;
}

void slDeleteNode(skiplist *sl, skiplistNode *x, skiplistNode **update) {

    for (int i = 0; i < sl->level; i ++) {
        if (update[i]->level[i].forward == x) {
            update[i]->level[i].span += x->level[i].span - 1;
            update[i]->level[i].forward = x->level[i].forward;
        } else {
            update[i]->level[i].span --;
        }
    }

    if (x->level[0].forward) {
        x->level[0].forward->backward = x->backward;
    } else {
        sl->tail = x->backward;
    }

    sl->length --;

    while (sl->level > 1 && sl->header->level[sl->level-1].forward == NULL) {
        sl->level --;
    }
}

skiplist *slCreate(void) {

    skiplist *sl = (skiplist*)malloc(sizeof(*sl));
    sl->length = 0;
    sl->level = 1;

    sl->header = slCreateNode(MAX_LEVEL, 0, ""); 
    for (int j = 0; j < MAX_LEVEL; j ++) {
        sl->header->level[j].forward = NULL;
        sl->header->level[j].span = 0;
    }

    sl->header->backward = NULL;
    sl->tail = NULL;
    return sl;
}

void slFree(skiplist *sl) {
    skiplistNode *node = sl->header->level[0].forward;

    while (node) {
        skiplistNode *next = node->level[0].forward;
        free(node);
        node = next;
    }

    free(sl->header);
    free(sl);
}

int getRandomLevel(double p) {
    int level = 1;
    while ((random()&0xffff) < (p*0xffff)) {
        level ++;
    }
    return level>MAX_LEVEL? MAX_LEVEL: level;
}

skiplistNode *slInsert(skiplist *sl, double score, sds ele) {
    skiplistNode *update[MAX_LEVEL], *x;
    int rank[MAX_LEVEL];

    x = sl->header;
    for (int i = sl->level-1; i >= 0; i --) {
        rank[i] = (i == sl->level-1)? 0: rank[i+1];
        while (x->level[i].forward &&
                (x->level[i].forward->score < score || 
                 (x->level[i].forward->score == score &&
                  strcmp(x->level[i].forward->ele, ele) < 0))) {

            rank[i] += x->level[i].span;
            x = x->level[i].forward;
        }

        update[i] = x;
    }

    int level = getRandomLevel(0.25);
    for (int i = sl->level; i < level; i ++) {
        rank[i] = 0; 
        update[i] = sl->header;
        update[i]->level[i].span = sl->length;
    }

    if (level > sl->level)  sl->level = level;
    x = slCreateNode(level, score, ele);

    for (int i = 0; i < sl->level; i ++) {
        x->level[i].forward = update[i]->level[i].forward;
        update[i]->level[i].forward = x;

        x->level[i].span = update[i]->level[i].span - (rank[0]-rank[i]);
        update[i]->level[i].span = rank[0]-rank[i]+1;
    }

    for (int i = level; i < sl->level; i ++)
        update[i]->level[i].span += 1;
    
    x->backward = (update[0] == sl->header) ?NULL: update[0];
    if (x->level[0].forward)
        x->level[0].forward->backward = x;
    else 
        sl->tail = x;

    sl->length ++;
    return x;
}

int slDelete(skiplist *sl, double score, sds ele, skiplistNode **node) {
    skiplistNode *update[MAX_LEVEL], *x;
    x = sl->header;
    for (int i = sl->level-1; i >= 0; i --) {
        while (x->level[i].forward &&
                (x->level[i].forward->score < score ||
                 (x->level[i].forward->score == score &&
                  strcmp(x->level[i].forward->ele, ele) < 0))) {
            x = x->level[i].forward;
        }
        update[i] = x;
    }

    //x = update[0]->level[0].forward;
    x = x->level[0].forward;
    if (x && x->score == score && strcmp(x->ele, ele) == 0) {
        slDeleteNode(sl, x, update);
        if (node) {
            *node = x;
        } else {
            free(x); 
        }
        return 1;
    } 
    return 0;
}

skiplistNode *slUpdateScore(skiplist *sl, double score, sds ele, double newscore) {
    skiplistNode *update[MAX_LEVEL], *x;
    x = sl->header;
    for (int i = sl->level-1; i >= 0; i --) {
        while (x->level[i].forward && 
                (x->level[i].forward->score < score || 
                 x->level[i].forward->score == score &&
                 strcmp(x->level[i].forward->ele, ele) == 0)) {
            x = x->level[i].forward;
        }

        update[i] = x;
    }

    x = x->level[0].forward;
    assert(x && x->score == score && strcmp(x->ele, ele) == 0);

    if ((x->backward == NULL || x->backward->score < newscore) &&
            (x->level[0].forward == NULL || x->level[0].forward->score > newscore)) {
        x->score = newscore;
        return x;
    }

    slDeleteNode(sl, x, update);
    skiplistNode *node = slInsert(sl, newscore, x->ele);

    x->ele = NULL;
    free(x);
    return node;
}
