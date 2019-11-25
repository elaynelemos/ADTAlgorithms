/**TAD HEADER NODE DOUBLE THREADED CIRCLED LIST
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo *next, *prev;
}NODO;

typedef NODO * HNDTC_LIST;

void criate(HNDTC_LIST*);

int empty(HNDTC_LIST);

int size(HNDTC_LIST);

int size_l(HNDTC_LIST);

void insert(HNDTC_LIST, int, int);

int recover(HNDTC_LIST, int);

void remove_l(HNDTC_LIST, int);

void print(HNDTC_LIST);

int pertence(HNDTC_LIST, int);

int eh_ord(HNDTC_LIST);

void generate(HNDTC_LIST, int, int);

void destroy(HNDTC_LIST);

void invert(HNDTC_LIST);


int main(){
	HNDTC_LIST list, list_g;
	int v, pos, m, n, op2;
	char op;
	criate(&list);
	criate(&list_g);
	printf("------------------------THREARED LIST------------------------------\n");
	do{
		printf("Operations:\nI - Insert\nE - Element\nR - Remove\nG - Generate\nV - Invert\nD - Destroy\nP - Print\nF - Finish\n");
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
			            destroy(list_g);
			        }
			        else{
			            printf("Invalid Option.");
			        }
			    }
			    break;
			}
			case 'V':{
			    invert(list);
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


void criate(HNDTC_LIST *pl){
	*pl = (NODO*)malloc(sizeof(NODO));
	if(!*pl){
		printf("Error! Insuficient Memory.\n");
		exit(1);
	}
	(*pl)->inf = 0;
	(*pl)->prev = *pl;
	(*pl)->next = *pl;
}


int empty(HNDTC_LIST pl){
	return ((pl->inf)?0:1);
}


int size(HNDTC_LIST pl){
	return (pl->inf);
}

	
void insert(HNDTC_LIST pl, int v, int k){
	HNDTC_LIST novo=NULL, aux;
	if(k<1 || k>pl->inf+1){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	novo = (NODO*)malloc(sizeof(NODO));
	if(!novo){
		printf("Error! Insuficient Memory.\n");
		exit(1);
	}
	novo->inf = v;
	if((pl->inf)==0){
		pl->next = novo;
		pl->prev = novo;
		novo->next = pl;
		novo->prev = pl;
	}
	else{
		for(aux=pl; k>1; k--, aux = aux->next);
		novo->next = aux->next;
		(aux->next)->prev = novo;
		aux->next = novo;
		novo->prev = aux;
	}
	pl->inf++;
}


int recover(HNDTC_LIST pl, int k){
	HNDTC_LIST a;
	if(k<1 || k>(pl->inf)){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(a=pl->next; --k; a = a->next);
	return (a->inf);
	
}


void remove_l(HNDTC_LIST pl, int k){
	HNDTC_LIST aux, aux2;
	if(k<1 || k>(pl->inf)){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	if(pl->inf==1){
	    aux = pl->next;
	    pl->next = pl;
	    pl->prev = pl;
	    free(aux);
	}
	else{
    	for(aux = pl; k>1; k--, aux = aux->next);
    	aux2 = aux->next;
    	aux->next = aux2->next;
    	(aux->next)->prev = aux;
    	free(aux2);
	}
	pl->inf--;
}


void print(HNDTC_LIST pl){
	printf("LIST = { ");
	if(pl->inf){
	    HNDTC_LIST a = pl;
    	while((pl->next)!=a){
    		pl = pl->next;
    		if((pl->next)!=a){
    			printf("%d, ", pl->inf);
    		}
    	}
		printf("%d ", pl->inf);
	}
	printf("}\n");
}


int pertence(HNDTC_LIST pl, int v){
    if(pl){
        HNDTC_LIST a = pl;
    	while(pl->next!=a){
    		pl = pl->next;
    		if(pl->inf==v) return (1);
    	}
    }
	return (0); 
}


int eh_ord(HNDTC_LIST pl){
	if(!pl || (pl->inf)==1) return 1;
	else{
	    HNDTC_LIST a = pl;
    	while(pl->next!=a){
    	    pl = pl->next;
    		if(pl->inf > (pl->next)->inf) return (0);
    	}
	}
	return (1);
}


void generate(HNDTC_LIST pl, int m, int n){
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


void destroy(HNDTC_LIST pl){
    HNDTC_LIST aux, aux2, list;
    if(pl->inf){
	    list = pl;
	    for(aux = pl->next; aux!=list; aux = aux->next){
	        aux2 = aux;
	        free(aux2);
	    }
        pl->next = pl;
        pl->prev = pl;
        pl->inf = 0;
	}
}


void invert(HNDTC_LIST pl){
    HNDTC_LIST aux, list, aux2;
    aux = pl;
    list = pl;
    if((list->inf)>1){
        do{
            aux2 = aux->prev;
            aux->prev = aux->next;
            aux->next = aux2;
            aux = aux->prev;
        }while(list!=aux);
    }
}


/*Funcoes recursivas: a verificar.

int recover_rec(HNDTC_LIST pl, int k){
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
*/

