#define ZSKIPLIST_MAXLEVEL 64
#define ZSKIPLIST_P 0.25
typedef char* sds;

typedef struct zskiplistLevel {
    struct zskiplistNode *forward;
    unsigned long span;
} zskiplistLevel; 

typedef struct zskiplistNode {
    sds ele;
    double score;
    struct zskiplistNode *backward;
    //struct zskiplistLevel {
    //    struct zskiplistNode *forward;
    //    unsigned long span;
    //} level[];
    zskiplistLevel level[];
} zskiplistNode;

typedef struct skiplist {
    struct zskiplistNode *header, *tail;
    unsigned long length;
    int level;
} zskiplist;

typedef struct {
    double min, max;
    int minex, maxex;
} zrangespec;

zskiplist *zslCreate(void);
void zslFree(zskiplist *zsl);
zskiplistNode *zslInsert(zskiplist *zsl, double score, sds ele);
int zslDelete(zskiplist *zsl, double score, sds ele, zskiplistNode **node);
zskiplistNode *zslFirstInRange(zskiplist *zsl, zrangespec *range);
zskiplistNode *zslLastInRange(zskiplist *zsl, zrangespec *range);
