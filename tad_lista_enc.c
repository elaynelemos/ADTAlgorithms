/**TAD THREADED LIST
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo * next;
}NODO;

typedef NODO * LISTA_ENC;

void criate(LISTA_ENC*);

int empty(LISTA_ENC);

int size(LISTA_ENC);

int size_l(LISTA_ENC);

void insert(LISTA_ENC*, int, int);

void insert_rec(LISTA_ENC*, int, int);

 int recover(LISTA_ENC, int);

void remove_l(LISTA_ENC*, int);

void remove_rec(LISTA_ENC*, int);

void print(LISTA_ENC);

int pertence(LISTA_ENC, int);

int eh_ord(LISTA_ENC);

void generate(LISTA_ENC*, int, int);

void destroy(LISTA_ENC*);


int main(){
	LISTA_ENC list, list_g;
	int v, pos, m, n;
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
				insert_rec(&list, v, pos);
				break;
			}
			case 'R':{
				printf("Position: ");
				scanf("%d", &pos);
				remove_rec(&list, pos);
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
			default: printf("Invalid option.\n");
		}
	}while(op != 'F');
	
	return 0;
} 	


void criate(LISTA_ENC *pl){
	*pl = NULL;
}

int empty(LISTA_ENC pl){
	return (!pl);
}

int size(LISTA_ENC pl){
	int tam=0;
	while(pl){
		pl = pl->next;
		tam++;
	}
	return tam;
}


int size_l(LISTA_ENC pl){
	if(!pl){
		return 0;
	}
	return (1 + size_l(pl->next));
}
	
void insert(LISTA_ENC *pl, int v, int p){
	int tam;
	LISTA_ENC novo=NULL, aux;
	tam = size(*pl);
	if(p<1 || p>tam+1){
		printf("Error! Invalid index.\n");
		exit(1);
	}
	novo = (NODO*)malloc(sizeof(NODO));
	novo->inf = v;
	if(!novo){
		printf("Error! Insuficient Memory.\n");
		exit(3);
	}
	if(p==1){
		novo->next = (*pl);
		(*pl) = novo;
	}
	else{
		for(aux=*pl; --p-1; aux = aux->next);
		novo->next = aux->next;
		aux->next = novo;
	}
	
}



void insert_rec(LISTA_ENC *pl, int v, int k){
	if(k>0 && k<=size(*pl)+1){
		if(!(k-1)){
			LISTA_ENC novo = NULL;
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


int recover(LISTA_ENC pl, int p){
	int tam;
	LISTA_ENC a;
	tam = size(pl);
	if(p<1 || p>tam){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(a=pl; --p; a = a->next);
	return (a->inf);
	
}

int recover_rec(LISTA_ENC pl, int k){
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
	

void remove_l(LISTA_ENC *pl, int p){
	int tam;
	tam = size(*pl);
	LISTA_ENC aux, aux2;
	if(p<1 || p>tam){
		printf("Error! Invalid index.\n");
		exit(1);
	}
	if(p==1){
		aux = *pl;
		*pl = (*pl)->next;
		free(aux);
	}
	else{
		for(aux = *pl; --p-1; aux = aux->next);
		aux2 = aux->next;
		aux->next = aux->next->next;
		free(aux2);
	}
}


void remove_rec(LISTA_ENC *pl, int k){
	if(k>0 && k<=size(*pl)){
		if(!(k-1)){
			LISTA_ENC aux;
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
	
	
	

void print(LISTA_ENC pl){
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


int pertence(LISTA_ENC l, int v){
	while(l){
		if(l->inf==v) return (1);
		l = l->next;
	}
	return (0); 
}


int eh_ord(LISTA_ENC l){
	if(!l) return 1;
	while(l->next){
		if(l->inf > (l->next)->inf) return (0);
		l = l->next;
	}

	return (1);
}



void generate(LISTA_ENC *pl, int m, int n){
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


void destroy(LISTA_ENC *pl){
    LISTA_ENC aux, aux2;
    for(aux = *pl; aux; aux = aux->next){
        aux2 = aux;
        *pl = aux->next;
        free(aux2);
    }
}










