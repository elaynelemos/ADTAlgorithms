
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INTGR 1
#define FLT 2
#define STR 3

typedef union{
	int ival;
	float fval;
	char sval[20];
}INF;

typedef struct node{
	int etype;
	INF element;
	struct node *next, *prev;
}NODE;

typedef NODE *DTNHC_LIST;

void criate(DTNHC_LIST*);

int empty(DTNHC_LIST);

int size(DTNHC_LIST);

int size_l(DTNHC_LIST);

void insert(DTNHC_LIST*, INF, int, int);

INF recover(DTNHC_LIST, int);

int belong(DTNHC_LIST, INF, int);

void remove_l(DTNHC_LIST*, int);

void print(DTNHC_LIST);

void destroy(DTNHC_LIST*);



int main(){
	DTNHC_LIST list, list_g;
	int v, pos, m, n, op2, t;
	INF e;
	char op;
	criate(&list);
	criate(&list_g);
	printf("------------------------THREARED LIST------------------------------\n");
	do{
		printf("Operations:\nI - Insert\nE - Element\nR - Remove\nG - Generate\nD - Destroy\nP - Print\nF - Finish\n");
		while(scanf("%c", &op), op==' ' || op=='\n');
		switch(op){
			case 'R':{
				printf("Position: ");
				scanf("%d", &pos);
				remove_l(&list, pos);
				break;
			}
			case 'E':{
				printf("Position: ");
				scanf("%d", &pos);
				e = recover(list, pos);
				break;
			}
			case 'I':{
				do{
					printf("Insertion element type:\n1 - Integer\n2 - Float\n3 - String\n");
					scanf("%d", &t);
				}while(t<1 || t>3);
				if(t==1){
					printf("Value: ");
					scanf("%d", &e.ival);
				}
				else{
					if(t==2){
						printf("Value: ");
						scanf("%f", &e.fval);
					}
					else{
						printf("String: ");
						fgets(e.sval, 20, stdin);
						if(e.sval[strlen(e.sval)-1]=='\n'){
							e.sval[strlen(e.sval)-1] = '\0';
						}
					}
				}
				printf("Position: ");
				scanf("%d", &pos);
				insert(&list, e, pos, t);
				break;
			}
			case 'D':{
			    printf("Which list [1 or 2]? ");
			    if(scanf("%d", &op2), op2==1){
			        destroy(&list);
			    }
			    else{
			        if(op2==2){
			            destroy(&list_g);
			        }
			        else{
			            printf("Invalid Option.");
			        }
			    }
			    break;
			}
			case 'F':{
				printf("Thanks for try.\n");
				break;
			}
			case 'P':{
				print(list);
				break;
			}
			default: printf("Invalid option.\n");
		}
	}while(op != 'F');
	
	return 0;
} 	


void criate(DTNHC_LIST *pl){
	*pl = NULL;
}


int empty(DTNHC_LIST pl){
	return (!pl);
}


int size(DTNHC_LIST pl){
	int tam=0;
	while(pl){
		pl = pl->next;
		tam++;
	}
	return tam;
}


int size_l(DTNHC_LIST pl){
	if(!pl){
		return 0;
	}
	return (1 + size_l(pl->next));
}

void insert(DTNHC_LIST *pl, INF v, int k, int t){
	int tam, ctrl=0;
	DTNHC_LIST novo=NULL, aux;
	tam = size(*pl);
	if(k<1 || k>tam+1){
		printf("Error! Invalid index.\n");
		exit(1);
	}
	if(t<INTGR || t>STR){
		printf("Error! Invalid element type.\n");
		exit(6);
	}
	novo = (NODE*)malloc(sizeof(NODE));
	if(!novo){
		printf("Error! Insuficient Memory.\n");
		exit(3);
	}
	if(!belong(*pl, v, t)){
		novo->element = v;
		novo->etype = t;
		if(k==1){
			if(tam){
				novo->prev = (*pl)->prev;
				novo->next = (*pl);
				(*pl) = novo;
				(novo->next)->prev = novo;
			}
			else{
				(*pl) = novo;
				(*pl)->next = novo;
				(*pl)->prev = novo;
			}
		}
		else{
			for(aux=*pl; --k-1; aux = aux->next);
			novo->prev = aux;
			novo->next = aux->next;
			aux->next = novo;
			(novo->next)->prev = novo;
		}
	}
}

INF recover(DTNHC_LIST pl, int k){
	int t;
	if(k<1 || k>size(pl)){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(; --k; pl = pl->next);
	t = pl->etype;
	if(t==INTGR){
		printf("%d\n", pl->element.ival);
	}
	else{
		if(t==FLT){
			printf("%.4f\n", pl->element.fval);
		}
		else{
			printf("%s\n", pl->element.sval);
		}
	}	
	return (pl->element);
}


int belong(DTNHC_LIST pl, INF v, int t){
	int i=0;
	DTNHC_LIST list=pl;
	if(pl){
		do{
			if(pl->etype==t){
				if((t==3 && !strcmp(pl->element.sval, v.sval)) || (t==1 && pl->element.ival==v.ival) || (t==2 && pl->element.fval==v.fval)){
				    return (1);
				}
			}
			pl = pl->next;
			printf("%d ", i++);
		}while(pl!=list);
	}
	return (0);
}


void remove_l(DTNHC_LIST *pl, int k){
	int tam;
	DTNHC_LIST aux;
	tam = size(*pl);
	if(k<1 || k>tam){
		printf("Error! Invalid index.\n");
		exit(1);
	}
	if(k==1){
		aux = *pl;
		if(tam > 1){
			(*pl) = (*pl)->next;
			(*pl)->prev = aux->prev;
		}
		else{
			(*pl) = NULL;
		}
		free(aux);
	}
	else{
		for(aux = *pl; --k; aux = aux->next);
		(aux->prev)->next = aux->next;
		(aux->next)->prev = aux->prev;
		free(aux);
	}
}


void print(DTNHC_LIST pl){
	int t;
	DTNHC_LIST list=pl;
	printf("LIST {\n");
	if(pl){
		do{
			t = pl->etype;
			if(t==INTGR){
				printf("%d\n", pl->element.ival);
			}
			else{
				if(t==FLT){
					printf("%.4f\n", pl->element.fval);
				}
				else{
					printf("%s\n", pl->element.sval);
				}
			}
			pl = pl->next;
		}while(pl!=list);
	}
	printf("}\n");
}



void destroy(DTNHC_LIST *pl){
    DTNHC_LIST aux, aux2;
    for(aux = *pl; aux; aux = aux->next){
        aux2 = aux;
        *pl = aux->next;
        free(aux2);
    }
}



