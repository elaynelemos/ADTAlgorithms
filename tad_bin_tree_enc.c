#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int inf;
    struct node *left, *right, *father;
}NODE;

typedef NODE* TREE_ENC;

void maketree(TREE_ENC*, int);

void setleft(TREE_ENC, int);

void setright(TREE_ENC, int);

int inf(TREE_ENC);

TREE_ENC left(TREE_ENC);

TREE_ENC right(TREE_ENC);

TREE_ENC father(TREE_ENC);

TREE_ENC brother(TREE_ENC);

int isleft(TREE_ENC);

int isleft(TREE_ENC);


int main(){}



void maketree(TREE_ENC *t, int v){
    *t = (NODE*)malloc(sizeof(NODE));
    if(!(*t)){
        printf("Error! Insuficient memory.\n");
        exit(2);
    }
    (*t)->father = NULL;
    (*t)->left = NULL;
    (*t)->right = NULL;
    (*t)->inf = v;
}


void setleft(TREE_ENC t, int v){
    TREE_ENC novo;
    novo = (NODE*)malloc(sizeof(NODE));
    if(!novo){
        printf("Error! Insuficient memory.\n");
        exit(3);
    }
    novo->inf = v;
    novo->father = t;
    novo->left = NULL;
    novo->right = NULL;
    t->left = novo;
}


void setright(TREE_ENC t, int v){
    TREE_ENC novo;
    novo = (NODE*)malloc(sizeof(NODE));
    if(!novo){
        printf("Error! Insuficient memory.\n");
        exit(4);
    }
    novo->inf = v;
    novo->father = t;
    novo->left = NULL;
    novo->right = NULL;
    t->right = novo;
}

int inf(TREE_ENC t){
    return t->inf;
}


TREE_ENC left(TREE_ENC t){
    return t->left;
}


TREE_ENC right(TREE_ENC t){
    return t->right;
}


TREE_ENC father(TREE_ENC t){
    return t->father;
}


TREE_ENC brother(TREE_ENC t){
    TREE_ENC f = t->father;
    if(f){
        if(isleft(t)){
            return f->right;
        }
        else{
            return f->left;
        }
    }
    return NULL;
}


int isleft(TREE_ENC t){
    TREE_ENC f = t->father;
    if(f){
        return((f)->left==t);
    }
    return 0;
}


int isright(TREE_ENC t){
    TREE_ENC f = t->father;
    if(f){
        return((f)->right==t);
    }
    return 0;
}

   
TREE_ENC search_tl(TREE_ENC t, int v){
    int control=0;
    if(t->inf){
        TREE_ENC aux=t;
        while(v!=aux->inf){
            if(isleft(aux)){
                aux = (aux->father)->right;
            }
            else{
                if(control)
                    while(isright(aux)){
                        aux = aux->father;  
                    }
            }
        }
    }
	
}


void search_pos(TREE_ENC t){
    if(t){
        search_pos(left(t));
        search_pos(right(t));
        printf("%d\n")
    }
    else{
        if(!right(t)){
            
        }
    }
}


void ins_ele(TREE_ENC *t, int v){
    TREE_ENC novo = (NODE*)malloc(sizeof(NODE));
    if(!novo){
        printf("Error! Insuficient memory.\n");
        exit(5);
    }
        novo->inf = v;
    if((*t)){
        b_search(t);
    }
    else{
    }
        
}



void remove_btf(TREE_ENC *t){
    if(*t){
        TREE_ENC aux = (*t)->left;
        while(aux->right){
            aux = aux->right;
        }
        aux->right = (*t)->right;
        aux = *t;
        *t = aux->left;
        free(aux);
    }
    else{
        printf("Error! Empty node.\n");
        exit(6);
    }
}




void remove_btc(TREE_ENC *t){
    if(*t){
        TREE_ENC tmp = (*t)->left;
        if(!tmp){
            tmp = (*t);
            (*t) = (*t)->right;
        }
        else{
            while(tmp->right){
                tmp = tmp->right;
            }
            tmp->left = (*t)->left;
            tmp->right = (*t)->right;
            tmp = *t;
            *t = tmp;
        }
        free(tmp);
    }
    else{
        printf("Error! Empty node.\n");
        exit(8);
    }
}




void improve_bt(TREE_ENC *t){
    if(*t){
        while(*t){
            
        }
    }
}




void bin_s(int *v, int n){
    
}





























    
    