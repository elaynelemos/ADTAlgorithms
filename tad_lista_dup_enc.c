/**TAD DOUBLE THREADED LIST
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo *next, *prev;
}NODO;

typedef NODO * DT_LIST;

void criate(DT_LIST*);

int empty(DT_LIST);

int size(DT_LIST);

int size_l(DT_LIST);

void insert(DT_LIST*, int, int);

void insert_rec(DT_LIST*, int, int);

 int recover(DT_LIST, int);

void remove_l(DT_LIST*, int);

void remove_rec(DT_LIST*, int);

void print(DT_LIST);

int pertence(DT_LIST, int);

int eh_ord(DT_LIST);

void generate(DT_LIST*, int, int);


void destroy(DT_LIST*);


void invert(DT_LIST*);


int main(){
	DT_LIST list, list_g;
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
				insert(&list, v, pos);
				break;
			}
			case 'R':{
				printf("Position: ");
				scanf("%d", &pos);
				remove_l(&list, pos);
				break;
			}
			case 'G':{
				printf("Set up inferior and superior limits [m n]: ");
				scanf("%d %d", &m, &n);
				generate(&list_g, m, n);
				print(list_g);
				break;
			}
			case 'E':{
				printf("Position: ");
				scanf("%d", &pos);
				printf("%d\n", recover(list, pos));
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
			case 'V':{
			    invert(&list);
			    break;
			}
			default: printf("Invalid option.\n");
		}
	}while(op != 'F');
	
	return 0;
} 	


void criate(DT_LIST *pl){
	*pl = NULL;
}


int empty(DT_LIST pl){
	return (!pl);
}


int size(DT_LIST pl){
	int tam=0;
	while(pl){
		pl = pl->next;
		tam++;
	}
	return tam;
}


int size_l(DT_LIST pl){
	if(!pl){
		return 0;
	}
	return (1 + size_l(pl->next));
}
	

void insert(DT_LIST *pl, int v, int k){
	int tam;
	DT_LIST novo=NULL, aux;
	tam = size(*pl);
	if(k<1 || k>tam+1){
		printf("Error! Invalid index.\n");
		exit(1);
	}
	novo = (NODO*)malloc(sizeof(NODO));
	if(!novo){
		printf("Error! Insuficient Memory.\n");
		exit(3);
	}
	novo->inf = v;
	if(k==1){
	    novo->prev = NULL;
		novo->next = (*pl);
		(*pl) = novo;
		if(tam){
			(novo->next)->prev = novo;
		}
	}
	else{
		for(aux=*pl; --k-1; aux = aux->next);
		novo->prev = aux;
		novo->next = aux->next;
		aux->next = novo;
		if(novo->next){
			(novo->next)->prev = novo;
		}
	}
}


int recover(DT_LIST pl, int k){
	int tam;
	DT_LIST a;
	tam = size(pl);
	if(k<1 || k>tam){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(a=pl; --k; a = a->next);
	return (a->inf);
	
}
	

void remove_l(DT_LIST *pl, int k){
	int tam;
	DT_LIST aux;
	tam = size(*pl);
	if(k<1 || k>tam){
		printf("Error! Invalid index.\n");
		exit(1);
	}
	if(k==1){
		aux = *pl;
		*pl = (*pl)->next;
		free(aux);
		if(tam > 1){
			(*pl)->prev = NULL;
		}
	}
	else{
		for(aux = *pl; --k; aux = aux->next);
		(aux->prev)->next = aux->next;
		if(aux->next){
			(aux->next)->prev = aux->prev;
		}
		free(aux);
	}
}


void print(DT_LIST pl){
	int i, tam;
	tam = size(pl);
	printf("LIST = { ");
	while(pl){
		if(pl->next==NULL) {
			printf("%d ", pl->inf);
			break;
		}
		printf("%d, ", pl->inf);
		pl = pl->next;
	}
	printf("}\n");
}


int pertence(DT_LIST l, int v){
	while(l){
		if(l->inf==v) return (1);
		l = l->next;
	}
	return (0); 
}


int eh_ord(DT_LIST l){
	if(!l) return 1;
	while(l->next){
		if(l->inf > (l->next)->inf) return (0);
		l = l->next;
	}

	return (1);
}


void generate(DT_LIST *pl, int m, int n){
	if(m>n){
		printf("Error! Invalid range.\n");
		exit(6);
	}
	if(m==n){
		insert(pl, m, 1);
	}
	else{
		generate(pl, m+1, n);
		insert(pl, m, 1);
	}
}


void destroy(DT_LIST *pl){
    DT_LIST aux, aux2;
    for(aux = *pl; aux; aux = aux->next){
        aux2 = aux;
        *pl = aux->next;
        free(aux2);
    }
}


void invert(DT_LIST *pl){
    int tam;
    tam = size(*pl); 
    if(tam>1){
        DT_LIST aux, aux2;
        aux = (*pl);
        while(tam--){
            aux2 = aux->prev;
            aux->prev = aux->next;
            aux->next = aux2;
            if(!(aux->prev)){
                *pl = aux;
            }
            aux = aux->prev;
        }
    }
}



/*Funcoes recursivas: a implementar.


void insert_rec(DT_LIST *pl, int v, int k){
	if(k>0 && k<=size(*pl)+1){
		if(!(k-1)){
			DT_LIST novo = NULL;
			novo = (NODO*)malloc(sizeof(NODO));
			if(!novo){
				printf("Error! Insuficient Memory.\n");
				exit(3);
			}
			novo->inf = v;
			novo->next = *pl;
			(*pl) = novo;
		}
		else{
			insert_rec(&((*pl)->next), v, k-1);
		}
	}
	else{
		printf("Error! Invalid Index.\n");
		exit(2);
	}
}

int recover_rec(DT_LIST pl, int k){
	if(k>0 && k<size(pl)+1){
		if(!(k-1))
			return (pl->inf);
		else
			return recover_rec(pl->next, k-1);
	}
	else{
		printf("Error! Invalid index.\n");
		exit(2);
	}
}	

void remove_rec(DT_LIST *pl, int k){
	if(k>0 && k<=size(*pl)){
		if(!(k-1)){
			DT_LIST aux;
			aux = *pl;
			*pl = (*pl)->next;
			free(aux);
		}
		else{
			remove_rec(&((*pl)->next), k-1);
		}
	}
	else{
		printf("Error! Invalid Index.\n");
		exit(4);
	}
}
*/




