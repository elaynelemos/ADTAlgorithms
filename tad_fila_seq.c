/**TAD QUEUE (FIFO LIST)
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
#define max 20

typedef struct {
	int N, begin, end, val[max];
}QUEUE;

void criate_sq(QUEUE*);

int empty_sq(QUEUE*);

void insert_sq(QUEUE*, int);

int size_sq(QUEUE*);

int cons_sq(QUEUE*);

void remove_sq(QUEUE*);

int cons_remove_sq(QUEUE*);

void generate_sq(QUEUE*, int, int);

void print_sq(QUEUE);


int main(){
	char op;
	int n, i, j;
	QUEUE queue;
	criate_sq(&queue);
	printf("-------------------------QUEUE--------------------------------\n");
	do{
		printf("Operations:\nI - Insert\nE - Element\nR - Remove\nG - Generate\nD - Destroy\nP - Print\nF - Finish\n");
		while(scanf("%c", &op), op==' ' || op=='\n');
		switch(op){
			case 'G':{
				printf("Range [m n]: ");
				scanf("%d %d", &i, &j);
				generate_sq(&queue, i, j);
				break;
			}
			case 'I':{
				printf("Value: ");
				scanf("%d", &n);
				insert_sq(&queue, n);
				break;
			}
			case 'P':{
				print_sq(queue);
				break;
			}
			case 'R':{
				remove_sq(&queue);
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


void criate_sq(QUEUE *q){
	q->N = q->begin = 0;
	q->end = -1;
}


int empty_sq(QUEUE *q){
	return (!q->N);
}


int size_sq(QUEUE *q){
    return (q->N);
}

void insert_sq(QUEUE *q, int v){
	if(q->N==max){
		printf("Error! Completed queue.\n");
		exit(5);
	}
	else{
		q->end = ((q->end)+1)%max;
		q->val[q->end] = v;
		q->N++;
	}
}


int cons_sq(QUEUE *q){
	if(q->N==0){
		printf("Error! Empty queue.\n");
		exit(2);
	}
	return (q->val[q->begin]);
}


void remove_sq(QUEUE *q){
	if(q->N){
		q->begin = ((q->begin)+1)%max;
		q->N--;
	}
	else{
		printf("Error! Empty queue.\n");
		exit(3);
	}
}


int cons_remove_sq(QUEUE *q){
	if(q->N){
		int v = q->val[q->begin];
		q->begin = ((q->begin)+1)%max;
		q->N--;
		return (v);
	}
	else{
		printf("Error! Empty queue.\n");
		exit(4);
	}
}


void generate_sq(QUEUE *q, int m, int n){
	if(n<m){
		printf("Error! Invalid range.\n");
		exit(6);
	}
	else{
		if(m==n){
			criate_sq(q);
			insert_sq(q, n);
		}
		else{
			generate_sq(q, m, n-1);
			insert_sq(q, n);
		}
	}
}

void print_sq(QUEUE q){
	printf("Queue:\n{");
	if(q.N){
		int tam = q.N, i;
		for(i=q.begin; i<tam; i++){
			if(i==max) i=0;
			printf("%5d", q.val[i]);
		}
	}
	printf("}\n");
}



