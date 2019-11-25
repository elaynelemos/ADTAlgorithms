/**TAD HEADER NODE THREADED LIST
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo * next;
}NODO;

typedef NODO * HN_LIST;

void criate(HN_LIST*);

int empty(HN_LIST);

int size(HN_LIST);

int size_l(HN_LIST);

void insert(HN_LIST, int, int);

int recover(HN_LIST, int);

void remove_l(HN_LIST, int);

void print(HN_LIST);

int pertence(HN_LIST, int);

int eh_ord(HN_LIST);

void generate(HN_LIST, int, int);

void destroy(HN_LIST);


int main(){
	HN_LIST list, list_g;
	int v, pos, m, n, op2;
	char op;
	criate(&list);
	criate(&list_g);
	printf("------------------------THREARED LIST------------------------------\n");
	do{
		printf("Operations:\nI - Insert\nE - Element\nR - Remove\nG - Generate\nD - Destroy\nP - Print\nF - Finish\n");
		while(scanf("%c", &op), op==' ' || op=='\n');
		switch(op){
			case 'I':{
				printf("Value: ");
				scanf("%d", &v);
				printf("Position: ");
				scanf("%d", &pos);
				insert(list, v, pos);
				break;
			}
			case 'R':{
				printf("Position: ");
				scanf("%d", &pos);
				remove_l(list, pos);
				break;
			}
			case 'G':{
				printf("Set up inferior and superior limits [m n]: ");
				scanf("%d %d", &m, &n);
				generate(list_g, m, n);
				break;
			}
			case 'E':{
				printf("Position: ");
				scanf("%d", &pos);
				printf("%d\n", recover(list, pos));
				break;
			}
			case 'F':{
				printf("Thanks for try.\n");
				break;
			}
			case 'D':{
			    printf("Which list [1 or 2]? ");
			    if(scanf("%d", &op2), op2==1){
			        destroy(list);
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
			case 'P':{
				print(list);
				break;
			}
			default: printf("Invalid option.\n");
		}
	}while(op != 'F');
	
	return 0;
} 	


void criate(HN_LIST *pl){
	*pl = (NODO*)malloc(sizeof(NODO));
	if(!*pl){
		printf("Error! Insuficient Memory.\n");
		exit(1);
	}
	(*pl)->inf = 0;
	(*pl)->next = NULL;
}


int empty(HN_LIST pl){
	return ((pl->inf)?0:1);
}


int size(HN_LIST pl){
	return (pl->inf);
}

	
void insert(HN_LIST pl, int v, int p){
	HN_LIST novo=NULL, aux;
	if(p<1 || p>pl->inf+1){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	novo = (NODO*)malloc(sizeof(NODO));
	if(!novo){
		printf("Error! Insuficient Memory.\n");
		exit(1);
	}
	novo->inf = v;
	for(aux=pl; --p; aux = aux->next);
	novo->next = aux->next;
	aux->next = novo;
	pl->inf++;
}


int recover(HN_LIST pl, int p){
	HN_LIST a;
	if(p<1 || p>(pl->inf)){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(a=pl->next; --p; a = a->next);
	return (a->inf);
	
}


int recover_rec(HN_LIST pl, int k){
	if(k>0 && k<size(pl)+1){
		if(!(k-1))
			return ((pl->next)->inf);
		else
			return recover_rec(pl->next, k-1);
	}
	else{
		printf("Error! Invalid index.\n");
		exit(2);
	}
}	
	

void remove_l(HN_LIST pl, int p){
	HN_LIST aux, aux2;
	if(p<1 || p>(pl->inf)){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(aux = pl; --p; aux = aux->next);
	aux2 = aux->next;
	aux->next = aux2->next;
	pl->inf--;
	free(aux2);
}


void print(HN_LIST pl){
	printf("LIST = { ");
	while(pl->next){
		if((pl->next)->next==NULL) {
			printf("%d ", (pl->next)->inf);
			break;
		}
		printf("%d, ", (pl->next)->inf);
		pl = pl->next;
	}
	printf("}\n");
}


int pertence(HN_LIST l, int v){
	while(l){
		if(l->inf==v) return (1);
		l = l->next;
	}
	return (0); 
}


int eh_ord(HN_LIST l){
	if(!l) return 1;
	while(l->next){
		if(l->inf > (l->next)->inf) return (0);
		l = l->next;
	}

	return (1);
}


void generate(HN_LIST pl, int m, int n){
	if(m>n){
		printf("Error! Invalid range.\n");
		exit(3);
	}
	if(m==n){
		insert(pl, m, 1);
	}
	else{
		generate(pl, m+1, n);
		insert(pl, m, 1);
	}
}


void destroy(HN_LIST pl){
    HN_LIST aux, aux2;
    for(aux = pl->next; aux; aux = aux->next){
        aux2 = aux;
        pl->next = aux->next;
        free(aux2);
        pl->inf--;
        
    }
}


