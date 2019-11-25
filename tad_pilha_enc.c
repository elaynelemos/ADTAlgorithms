/**TAD THREARED HEAP(LIFO LIST)
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>


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


int main(){
	char op;
	int n, i, j;
	HEAP_T heap;
	criate_th(&heap);
	printf("-------------------------heap--------------------------------\n");
	do{
		printf("Operations:\nI - Insert\nC - Consult\nR - Remove\nG - Generate\nD - Destroy\nP - Print\nF - Finish\n");
		while(scanf("%c", &op), op==' ' || op=='\n');
		switch(op){
		    case 'C':{
		        printf("First element: %d\n", top_th(heap));
		        break;
		    }
			case 'I':{
				printf("Value: ");
				scanf("%d", &n);
				push_th(&heap, n);
				break;
			}
			case 'R':{
				pop_th(&heap);
				break;
			}
			case 'P':{
				print_th(heap);
				break;
			}/*			
			case 'G':{
				printf("Range [m n]: ");
				scanf("%d %d", &i, &j);
				generate_th(&heap, i, j);
				break;
			}
			case 'D':{
			    destroy_th(&heap);
			    break;
			}*/
			case 'F':{
				printf("Thanks for try.\n");
				break;
			}			
			default: printf("Invalid option.\n");
		}
	}while(op != 'F');
	
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


/*
void entry(char *s){
    int size;
    printf("Operation: ");
    fgets(s, max, stdin);
    size = strlen(s);
    if(s[size-1]=='\n'){
        s[size-1] = '\0';
    }
}

int tree_op(char *s){
    char aux[2];
    int i, size, a;
    HEAP_T h;
    create(&h);
    size = strlen(s);
    aux[1] = '\0';
    for(i==0; i<size; ++i){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^'){
            a = top_pop(h);
            b = top_pop(h);
            switch(s[i]){
                case '+':{
                    push(&h, b+a);
                }
                case '-':{
                    push(&h, b-a);
                }
                case '*':{
                    push(&h, b*a);
                    break;
                }
                case '/':{
                    if(!a){
                        push(&h, b/a);
                        break;
                    }
                    else{
                        printf("Error! invalid operation.");
                        exit(10);
                    }
                }
                case '^':{
                    push(&h, (int)pow(b,a));
                    break;
                }
            }
        }
        else{
            aux[0] = s[i];
            sscanf(aux, "%d", &a);
            push(&h, a);
        }
    }
    return (top_pop(&h));
}



void converter_s_p(char *o, char *d){
    char symbol;
    int i1=0, i2=0;
    PILHA_ENC opstk;
    cria_pilha (&opstk);
    while (symbol=o[i1++])
        if (eh_operando(symbol))
            d[i2++]=symbol;
        else
        {
            while (!eh_vazia(opstk) && prcd(top(opstk),symbol))
                d[i2++]=top_pop(&opstk);
            push(&opstk, symbol); 
        }
    while (!eh_vazia(opstk))
        d[i2++]=top_pop(&opstk);
    d[i2]='\0';
}


int prcd (char op1, char op2){
    if((op1!=')' && op2=='(') || (op1=='(' && op2!=')') || (op1=='(' && op2==')'))
        return (0);
    if(op1!='(' && op2!=')')
        return (1);
    if ((op1=='+' || op1=='-') && (op2=='+' || op2=='-'))
        return (1);
    if ((op1=='*' || op1=='/') && (op2=='+' || op2=='-' || op2=='*' || op2=='/'))
        return (1);
    return (1);
    if (op1=='^' && (op2=='^' || op2=='+' || op2=='-' || op2=='*' || op2=='/'))
        return (1);
return (0);
}

*/


