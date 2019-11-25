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
	NODE *begin, *end;
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

void ordering_list(QUEUE, int, int, int);


int main(){
	char op;
	int n, i, d, b, v;
	QUEUE queue;
	criate_tq(&queue);
	printf("-------------------------ORDERING QUEUE--------------------------------\n");
	printf("How many keys does your list have? ");
	scanf("%d", &n);
	if(n>0){
	    printf("Values max lenght: ");
	    scanf("%d", &d);
	    printf("Base: ");
	    scanf("%d", &b);
        printf("Entry: ");
        for(i=0; i<n; ++i){
            printf("%d - ", i+1);
            scanf("%d", &v);
            insert_tq(queue, v);
        }
        printf("Before ordering: \n");
        print_tq(queue);
        ordering_list(queue, n, b, d);
        printf("Ordered list: \n");
        print_tq(queue);
    }
    else{
        printf("Error! Invalid size.\n");
    }
	
	return 0;
} 	


void criate_tq(QUEUE *q){
    (*q) = (DESCRIBER*)malloc(sizeof(DESCRIBER));
	(*q)->size = 0;
	(*q)->end = (*q)->begin = NULL;
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
        novo->next = NULL;
        novo->inf = v;
        if(q->size){
            (q->end)->next = novo;
        }
        else{
            q->begin = novo;
        }
        q->end = novo;
        q->size++;
    }
}


int consult_tq(QUEUE q){
    if(q->size){
        return ((q->begin)->inf);
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
        aux = q->begin;
        if(s==1){
            q->begin = q->end = NULL;
        }
        else{
            q->begin = aux->next;
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
        NODE *aux;
        aux = q->begin;
        v = aux->inf;
        if(s==1){
            q->begin = q->end = NULL;
        }
        else{
            q->begin = aux->next;
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
        NODE *aux;
        aux = q->begin;
        while(aux){
            printf("%10d", aux->inf);
            aux = aux->next;
        }
    }
    printf("\n");
}


void destroy_tq(QUEUE q){
    while(q->begin){
        remove_tq(q);
    }
}


void ordering_list(QUEUE q, int n, int b, int d){
    int i, j, p, v;
    QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE)*b);
    
    for(i=0; i<b; ++i){
        criate_tq(queue+i);
    }
    
    for(i=0; i<d; ++i){
        for(j=0; j<n; ++j){
            v = cons_rem_tq(q);
            p = (v%((int)pow(10,i+1)))/((int)pow(10, i));
            insert_tq(queue[p], v);
        }
        for(j=0; j<b; ++j){
            while(!empty_tq(queue[j])){
                insert_tq(q, cons_rem_tq(queue[j]));
            }
        }
    }
}
