/**TAD THREARED HEAP (LIFO LIST) APPLICATION
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define max 100


typedef struct node{
    int inf;
    struct node *prev;
}NODE;

typedef NODE* HEAP_T;

void criate_th(HEAP_T*);

int empty_th(HEAP_T);

void push_th(HEAP_T*, int);

int top_th(HEAP_T);

void pop_th(HEAP_T*);

int top_pop_th(HEAP_T*);

void print_th(HEAP_T);

int evaluate(char*);

int operand(char);

int operate(int, char, int);



int main(){
	char expression[max];
	printf("\n_________Evaluate a mathematics expression (heap application)_________\n\n");
	printf("Expression: \n");
	fgets(expression, max, stdin);
	if(expression[strlen(expression)-1]=='\n'){
	    expression[strlen(expression)-1] = '\0';
	}
	printf("%s = %d\n", expression, evaluate(expression));
	return 0;
} 	


void create_th(HEAP_T *h){
    *h = NULL;
}


int empty_th(HEAP_T h){
    return (h==NULL);
}


void push_th(HEAP_T *h, int v){
    HEAP_T novo=(NODE*)malloc(sizeof(NODE));
    if(!novo){
        printf("Error! Insuficient memory.\n");
        exit(1);
    }
    else{
        HEAP_T aux = *h;
        novo->inf = v;
        novo->prev = aux;
        *h = novo;
    }
}


int top_th(HEAP_T h){
    if(!empty_th(h)){
        return (h->inf);
    }
    else{
        printf("Error! Empty heap.\n");
        exit(2);
    }
}


void pop_th(HEAP_T *h){
    if(!empty_th(*h)){
        HEAP_T aux;
        aux = (*h);
        *h = aux->prev;
        free(aux);
    }
    else{
        printf("Error! Empty heap.\n");
        exit(3);
    }
}


int top_pop_th(HEAP_T *h){
    if(!empty_th(*h)){
        int v;
        HEAP_T aux;
        aux = (*h);
        v = aux->inf;
        *h = aux->prev;
        free(aux);
        return (v);
    }
    else{
        printf("Error! Empty heap.\n");
        exit(4);
    }
}


void print_th(HEAP_T h){
	printf("\tHeap: \n");
	if(h){
		do{
			printf("%5d", h->inf);
			h = h->prev;
		}while(h);
	}
	printf("\n");
}


int evaluate(char *e){
    char symbol;
    int i;
    HEAP_T op_heap;
    create_th(&op_heap);
    for(i=0; symbol=e[i]; ++i){
        if(operand(symbol))
            push_th(&op_heap, symbol-'0');
        else{
            int op2=top_pop_th(&op_heap), op1=top_pop_th(&op_heap);
            push_th(&op_heap, operate(op1, symbol, op2));
        }
    }
    return (top_pop_th(&op_heap));
}


int operand(char c){
    return(!(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'));
}


int operate(int op1, char o, int op2){
    switch(o){
        case '+': return(op1+op2);
        case '-': return(op1-op2);
        case '*': return(op1*op2);
        case '/': return(op1/op2);
        case '^': return((int)pow(op1, op2));
        default: {
            printf("Error! Invalid operator.\n");
            exit(10);
        }
    }
}








