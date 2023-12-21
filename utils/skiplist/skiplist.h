#include <string.h>
#define MAX_LEVEL 64

typedef char* sds;

// c++ needs this defination
//typedef struct skiplistLevel{
//    struct skiplistNode *forward;
//    unsigned long span;
//} skiplistLevel;

typedef struct skiplistNode {
    sds ele;
    double score;
    struct skiplistNode *backward;
    struct skiplistLevel {
        struct skiplistNode *forward;
        unsigned long span;
    } level[];
} skiplistNode;

typedef struct skiplist {
    struct skiplistNode *header, *tail;
    unsigned long length;
    int level;
} skiplist;


skiplistNode *slCreateNode(int level, double score, sds ele);
void slDeleteNode(skiplist *sl, skiplistNode *x, skiplistNode **update);

skiplist *slCreate(void);
void slFree(skiplist *sl);
skiplistNode *slInsert(skiplist *sl, double score, sds ele);
int slDelete(skiplist *sl, double score, sds ele, skiplistNode **node);
skiplistNode *slUpdateScore(skiplist *sl, double score, sds ele, double newscore);
//int getRandomLevel(double p);
