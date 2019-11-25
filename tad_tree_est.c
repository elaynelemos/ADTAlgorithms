#include <stdio.h>
#define NUMNODES 100

typedef struct{
    int info, left, right, father;
}NODE;
typedef struct{
    int root, nodeFree;
    NODE nodes[NUMNODES];
}TREE_BIN_SEQ;

void maketree(TREE_BIN_SEQ*, int);

void setleft(TREE_BIN_SEQ*, int, int);

void setright(TREE_BIN_SEQ*, int, int);

void maketree(TREE_BIN_SEQ*, int);

void maketree(TREE_BIN_SEQ*, int);

void maketree(TREE_BIN_SEQ*, int);

void maketree(TREE_BIN_SEQ*, int);
