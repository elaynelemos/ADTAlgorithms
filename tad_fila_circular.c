/**TAD THREARED QUEUE APPLCATION (FIFO LIST)
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodo {
	int inf;
	struct nodo *next;
}NODE;

typedef struct {
	unsigned int size;
	NODE *end;
}DESCRIBER;

typedef DESCRIBER* QUEUE;

void criate_tq(QUEUE*);

int empty_tq(QUEUE);

int size_tq(QUEUE);

void insert_tq(QUEUE, int);

int consult_tq(QUEUE);

void remove_tq(QUEUE);

int cons_rem_tq(QUEUE);

void generate_tq(QUEUE*, int, int);

void print_tq(QUEUE);

void destroy_tq(QUEUE);


int main(){
    
}


void criate_tq(QUEUE *q){
    (*q) = (DESCRIBER*)malloc(sizeof(DESCRIBER));
	(*q)->size = 0;
	(*q)->end = NULL;
}

int empty_tq(QUEUE q){
    return !(q->size);
}

int size_tq(QUEUE q){
    return (q->size);
}


void insert_tq(QUEUE q, int v){
    NODE *novo = (NODE*)malloc(sizeof(NODE));
    if(!novo){
        printf("Error! Insuficient memory.\n");
        exit(2);
    }
    else{
        novo->inf = v;
        if(q->size){
            novo->next = (q->end)->next;
        }
        novo->next = novo;
        q->end = novo;
        q->size++;
    }
}


int consult_tq(QUEUE q){
    if(q->size){
        return (((q->end)->next)->inf);
    }
    else{
        printf("Error! Empty queue.\n");
        exit(5);
    }
}


void remove_tq(QUEUE q){
    int s = q->size;
    if(s){
        NODE *aux;
        aux = (q->end)->next;
        if(s==1){
            q->end = NULL;
        }
        else{
            (q->end)->next = aux->next;
        }
        free(aux);
        q->size--;
    }
    else{
        printf("Error! Empty queue.\n");
        exit(6);
    }
}


int cons_rem_tq(QUEUE q){
    int s = q->size;
    if(s){
        int v;
        NODE *aux = (q->end)->next;
        v = aux->inf;
        if(s==1){
            q->end = NULL;
        }
        else{
            (q->end)->next = aux->next;
        }
        free(aux);
        q->size--;
        return (v);
    }
    else{
        printf("Error! Empty queue.\n");
        exit(7);
    }
}


void generate_tq(QUEUE *q, int m, int n){
    if(m>n){
        printf("Error! Invalid range.\n");
        exit(10);
    }
    else{
        if(m==n){
            criate_tq(q);
            insert_tq(*q, n);
        }
        else{
            generate_tq(q, m, n-1);
            insert_tq(*q, n);
        }
    }
}


void print_tq(QUEUE q){
    printf("Queue:\n");
    if(q->size){
        NODE *aux, *queue;
        queue = aux = (q->end)->next;
        do{
            printf("%5d", aux->inf);
            aux = aux->next;
        }while(aux!=queue);
    }
    printf("\n");
}


void destroy_tq(QUEUE q){
    while(q->end){
        remove_tq(q);
    }
}





