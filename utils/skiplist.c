#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "skiplist.h"

skiplistNode *slCreateNode(int level, double score, sds ele) {

    skiplistNode *sn = (skiplistNode*) malloc(sizeof(*sn) + level*sizeof(struct skiplistLevel));

    sn->score = score;
    sn->ele = ele;
    return sn;
}

void slDeleteNode(skiplist *sl, skiplistNode *x, skiplistNode **update) {

}

skiplist *slCreate(void) {

    skiplist *sl = (skiplist*)malloc(sizeof(*sl));
    sl->length = 0;
    sl->level = 1;

    sl->header = slCreateNode(MAX_LEVEL, 0, ""); 
    for (int j = 0; j < MAX_LEVEL; j ++) {
        sl->header->level[0].forward = NULL;
        sl->header->level[0].span = 0;
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

    for (int i = sl->level-1; i >= 0; i --) {
        x = sl->header;
        rank[i] = (i == sl->level-1)? 0: rank[i+1];
        while (x->level[i].forward && (
            x->score < score || 
            (x->score == score && strcmp(x->ele, ele) < 0))) {

            x = x->level[i].forward;
            rank[i] += x->level[i].span;
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
        while (x->level[i].forward && (x->score < score ||
                    x->score == score && strcmp(x->ele, ele) < 0)) {
            x = x->level[i].forward;
        }
        update[i] = x;
    }


    slDeleteNode(sl, x, update);
    //for (int i = 0; i < sl->level; i ++) {
    //    update[i]->level[i].forward = x->level[i].forward;
    //    update[i]->level[i].span += x->level[i].span - 1;
    //}

    //if (update[0] == sl->header) {
    //    sl->tail = x->level[0].forward;      
    //}

    //if (update[0]->backward) {
    //    x->backward = update[0]->backward;
    //}

    ////free(x);
    //*node = x;
    //sl->length --;

    //while (sl->header->level[sl->level-1].forward == NULL) {
    //    sl->level --;
    //}
    return 1;
}

skiplistNode *slUpdate(skiplist *sl, double score, sds ele, double newscore) {
    skiplistNode *update[MAX_LEVEL], *x;
    x = sl->header;
    for (int i = sl->level-1; i >= 0; i --) {
        while (x->level[i].forward && (x->score < score || 
                    x->score == score && strcmp(x->ele, ele))) {
            x = x->level[i].forward;
        }

        update[i] = x;
    }

}
