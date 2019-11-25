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

void create_tq(QUEUE*);

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
	char op;
	int n, i, j;
	QUEUE queue;
	create_tq(&queue);
	printf("-------------------------QUEUE--------------------------------\n");
	do{
		printf("Operations:\nI - Insert\nC - Consult\nR - Remove\nG - Generate\nD - Destroy\nP - Print\nF - Finish\n");
		while(scanf("%c", &op), op==' ' || op=='\n');
		switch(op){
		    case 'C':{
		        printf("First element: %d\n", consult_tq(queue));
		        break;
		    }
			case 'G':{
				printf("Range [m n]: ");
				scanf("%d %d", &i, &j);
				generate_tq(&queue, i, j);
				break;
			}
			case 'I':{
				printf("Value: ");
				scanf("%d", &n);
				insert_tq(queue, n);
				break;
			}
			case 'P':{
				print_tq(queue);
				break;
			}
			case 'R':{
				remove_tq(queue);
				break;
			}
			case 'D':{
			    destroy_tq(queue);
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



void create_tq(QUEUE *q){
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


void generate_tq(QUEUE *q, int m, int n){
    if(m>n){
        printf("Error! Invalid range.\n");
        exit(10);
    }
    else{
        if(m==n){
            create_tq(q);
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
            printf("%5d", aux->inf);
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





