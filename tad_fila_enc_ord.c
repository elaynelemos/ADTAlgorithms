/**TAD THREARED QUEUE (FIFO LIST)
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int inf;
	struct nodo *next;
}NODE;

typedef struct {
	unsigned int size;
	NODE *begin, *end;
}DESCRIBER;

typedef DESCRIBER* QUEUE;

void criate(QUEUE*);

int empty(QUEUE);

int size_q(QUEUE);

void insert(QUEUE, int);

int consult(QUEUE);

void remove_q(QUEUE);

int cons_rem(QUEUE);

void generate(QUEUE*, int, int);

void print(QUEUE);


int main(){
	char op;
	int n, i, j;
	QUEUE queue;
	criate(&queue);
	printf("-------------------------QUEUE--------------------------------\n");
	do{
		printf("Operations:\nI - Insert\nC - Consult\nR - Remove\nG - Generate\nD - Destroy\nP - Print\nF - Finish\n");
		while(scanf("%c", &op), op==' ' || op=='\n');
		switch(op){
		    case 'C':{
		        printf("First element: %d\n", consult(queue));
		        break;
		    }
			case 'G':{
				printf("Range [m n]: ");
				scanf("%d %d", &i, &j);
				generate(&queue, i, j);
				break;
			}
			case 'I':{
				printf("Value: ");
				scanf("%d", &n);
				insert(&queue, n);
				break;
			}
			case 'P':{
				print(queue);
				break;
			}
			case 'R':{
				remove_q(&queue);
				break;
			}
			case 'F':{
				printf("Thanks for try.\n");
				break;
			}			
			default: printf("Invalid option.\n");
		}
	}while(op != 'F');
	
	return 0;
} 	



void criate(QUEUE *q){
	(*q)->size = 0;
	(*q)->end = (*q)->begin = NULL;
}

int empty(QUEUE q){
    return !(q->size);
}

int size_q(QUEUE q){
    return (q->size);
}

void insert(QUEUE q, int v){
    int s = q->size;
    NODE novo = (NODE*)malloc(sizeof(NODE));
    if(!novo){
        printf("Error! Insuficient memory.\n");
        exit(2);
    }
    else{
        novo->next = NULL;
        novo->inf = v;
        if(s){
            (q->end)->next = novo;
        }
        else{
            q->begin = novo;
        }
        q->end = novo;
        q->size++;
    }
}


int consult(QUEUE q){
    if(q->size){
        return ((q->begin)->inf);
    }
    else{
        printf("Error! Empty queue.\n");
        exit(5);
    }
}


void remove_q(QUEUE q){
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

int cons_rem(QUEUE q){
    int s = q->size;
    if(s){
        int v;
        NODE *aux;
        v = aux->inf;
        aux = q->begin;
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


void generate(QUEUE *q, int m, int n){
    if(m>n){
        printf("Error! Invalid range.\n");
        exit(10);
    }
    else{
        if(m==n){
            criate(q);
            insert(n);
        }
        else{
            generate(q, m, n-1);
            insert(q, n);
        }
    }
}

void print(QUEUE q){
    printf("Queue:\n");
    if(q->size){
        NODE *aux;
        aux = q->begin;
        while(aux){
            printf("%5d", aux->inf);
        }
    }
    printf("\n");
}

void ord(QUEUE *q, int b, int d){
	int i, j, k, end;
	QUEUE v[b];
	NODE aux;
	criate(&aux);
	for(j=1; j<=d; j++){
		aux = q->begin;	
		for(i=0; i<b; i++){
			for(
			end = aux->inf%(10*j);
			if(v[
		}
	}
}

QUEUE concat(QUEUE a, QUEUE b){
	(a->end)->next = b->begin;
	a->end = b->end;
	free(b);
	return (a);
} 






