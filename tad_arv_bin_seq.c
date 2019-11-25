#include <stdio.h>
#define N_NODES 100

typedef struct{
    int inf, left, right, father;
}NODE;

typedef struct{
    int root, nodeFree;
    NODE nodes[N_NODES];
}BIN_SEQ_T;

void maketree(BIN_SEQ_T *, int);
void setleft(BIN_SEQ_T *, int, int);
void setright(BIN_SEQ_T *, int, int);
int info(BIN_SEQ_T *, int);
int left(BIN_SEQ_T *, int);
int right(BIN_SEQ_T *, int);
int father(BIN_SEQ_T *, int);
int brother(BIN_SEQ_T *, int);
int isleft(BIN_SEQ_T *, int);
int isright(BIN_SEQ_T *, int);


int main(){
    
}


void maketree(BIN_SEQ_T *t, int v){
    int i;
    t->root = 0;
    t->nodeFree = 1;
    t->nodes[0]->father = -1;
    t->nodes[0]->left = -1;
    t->nodes[0]->right = -1;
    t->nodes[0]->inf = v;
    for(i=1; i<N_NODES; ++i){
        t->nodes[i]->father = -1;
        t->nodes[i]->left = i+1;
        t->nodes[i]->right = -1;   
    }
    t->nodes[i-1]->left = -1;
}


void setleft(BIN_SEQ_T *t, int p, int v){
    int nd=t->nodeFree;
    if(nd>0){
        t->nodes[p]->left = nd;
        t->nodeFree = t->nodes[nd]->left;
        t->nodes[nd]->inf = v;
        t->nodes[nd]->left = -1;
    }
    else{
        printf("Error! No more space available.\n");
        exit(2);
    }
}


void setright(BIN_SEQ_T *t, int p, int v){
    int nd=t->nodeFree;
    if(nd>0){
        t->nodes[p]->right = nd;
        t->nodeFree = t->nodes[nd]->left;
        t->nodes[nd]->inf = v;
        t->nodes[nd]->left = -1;
    }
    else{
        printf("Error! No more space available.\n");
        exit(2);
    }
}

int info(BIN_SEQ_T *t, int p){
    return (t->nodes[p].inf);
}


int left(BIN_SEQ_T *t, int p){
    return (t->nodes[p].left);
}


int right(BIN_SEQ_T *t, int p){
    return (t->nodes[p].right);
}


int father(BIN_SEQ_T *t, int p){
    return (t->nodes[p].father);
}


int brother(BIN_SEQ_T *t, int p){
    int nd = father(t, p);
    if(nd>=0){
        if(isleft(t, p))
            return (right(t, nd));
        return (left(t, nd));
    }
    return (-1);
}


int isleft(BIN_SEQ_T *t, int p){
    int nd = father(t, p);
    if(nd>=0){
        if(t->nodes[nd]->left==p)
            return (1);
        return (0);
    }
    return (0);
}

int isright(BIN_SEQ_T *t, int p){
    int nd = father(t, p);
    if(nd>=0){
        if(t->nodes[nd]->right==p)
            return (1);
        return (0);
    }
    return (0);
}


