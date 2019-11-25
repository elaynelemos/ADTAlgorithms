/**TAD HEAP(LIFO LIST)
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
#define max 20

typedef struct{
	int val[max], top;
}HEAP;

void criate(HEAP*);

int empty(HEAP*);

void push(HEAP*, int);

int top(HEAP*);

void pop(HEAP*);

int top_pop(HEAP*);

void invert(HEAP*);

void print(HEAP);


int main(){
    HEAP h;
	int v, pos, m, n, op2;
	char op;
	criate(&h);
	printf("------------------------HEAP------------------------------\n");
	do{
		printf("Operations:\nU - Push\nT - Top\nO - Pop\nP - Top-Pop\nV - Invert\nF - Finish\n");
		while(scanf("%c", &op), op==' ' || op=='\n');
		switch(op){
			case 'U':{
				printf("Value: ");
				scanf("%d", &v);
				push(&h, v);
				break;
			}
			case 'T':{
			    top(&h);
				break;
			}
			case 'O':{
			    pop(&h);
				break;
			}
			case 'P':{
				printf("%d\n", top_pop(&h));
				break;
			}
			case 'F':{
				printf("Thanks for try.\n");
				break;
			}
			case 'V':{
			    invert(&h);
			    break;
			}
			case 'P':{
				print(h);
				break;
			}
			default: printf("Invalid option.\n");
		}
	}while(op != 'F');
	
	return 0;
} 	


void criate(HEAP *h){
	h->top = -1;	
}


int empty(HEAP *h){
	return ((h->top)==-1?1:0);
}

void push(HEAP *h, int v){
	int aux = h->top;
	if(aux<max-1){
		v[++aux] = v;
		h->top = aux;
	}
	else{
		printf("Error! It is full.\n");
		exit(3);
	}
}


void pop(HEAP *h){
	if(!empty(h)){
		(h->top)--;
	}
	else{
		printf("Error! Empty heap.\n");
		exit(4);
	}
}


int top(HEAP *h){
	if(!empty(h)){
		return (h->v[h->top]);
	}
	else{
		printf("Error! Empty heap.\n");
		exit(2);
	}
}

int top_pop(HEAP *h){
	if(!empty(h)){
		(h->top)--;
		return (h->val[(h->top)+1]);
	}
	else{
		printf("Error! Empty heap.\n");
		exit(6);
	}
}

void invert(QUEUE *h){
    int total = h->top;
    if(total > 0){
        int aux, i;
        for(i=0; i<=total/2; i++){
            aux = h->val[i];
            val[i] = val[total-i];
            val[total-i] = aux;
        }
    }
}

void print(HEAP h){
    int total;
    total = h.top;
    if(total>=0){
        do{
            printf("%d\n", h.val[total]);
        }while(total--);
    }
}
















