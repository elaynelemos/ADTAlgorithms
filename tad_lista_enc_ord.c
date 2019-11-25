/**TAD THREADED AND ORDERED LIST
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo * next;
}NODO;

typedef NODO * ORD_LIST;

void criate(ORD_LIST*);

int empty(ORD_LIST);

int size(ORD_LIST);

int size_l(ORD_LIST);

void insert(ORD_LIST*, int);

void insert_rec(ORD_LIST*, int);

int recover(ORD_LIST, int);

void remove_l(ORD_LIST*, int);

void remove_rec(ORD_LIST*, int);

int remove_rec_v(ORD_LIST*, int);

void print(ORD_LIST);

int pertence(ORD_LIST, int);

void generate(ORD_LIST*, int, int);

void destroy(ORD_LIST*);


int main(){
	ORD_LIST list, list_g;
	int v, pos, m, n, op2;
	char op;
	criate(&list);
	criate(&list_g);
	printf("------------------------THREARED LIST------------------------------\n");
	do{
		printf("Operations:\nI - Insert\nE - Element\nR - Remove\nV - Remove by Value\nD - Destroy\nG - Generate\nP - Print\nF - Finish\n");
		while(scanf("%c", &op), op==' ' || op=='\n');
		switch(op){
			case 'I':{
				printf("Value: ");
				scanf("%d", &v);
				insert_rec(&list, v);
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
			case 'F':{
				printf("Thanks for try.\n");
				break;
			}
			case 'P':{
				print(list);
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
			case 'V':{
				printf("Value: ");
				scanf("%d", &v);
				remove_rec_v(&list, v);
				break;				
			}
			default: printf("Invalid option.\n");
		}
	}while(op != 'F');
	
	return 0;
} 	


void criate(ORD_LIST *pl){
	*pl = NULL;
}


int empty(ORD_LIST pl){
	return (!pl);
}


int size(ORD_LIST pl){
	int tam=0;
	while(pl){
		pl = pl->next;
		tam++;
	}
	return tam;
}


int size_l(ORD_LIST pl){
	if(!pl){
		return 0;
	}
	return (1 + size_l(pl->next));
}

	
void insert(ORD_LIST *pl, int v){
	ORD_LIST novo=NULL, aux;
	novo = (NODO*)malloc(sizeof(NODO));
	novo->inf = v;
	if(!novo){
		printf("Error! Insuficient Memory.\n");
		exit(3);
	}
	if(!(*pl) || (*pl)->inf > v){
		novo->next = (*pl);
		(*pl) = novo;
	}
	else{
		for(aux=*pl; ((aux->next) && ((aux->next)->inf < v)); aux = aux->next);
		novo->next = aux->next;
		aux->next = novo;
	}
	
}


void insert_rec(ORD_LIST *pl, int v){
	if(!(*pl) || (*pl)->inf > v){
		ORD_LIST novo = NULL;
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
		insert_rec(&((*pl)->next), v);
	}
}


int recover(ORD_LIST pl, int p){
	int tam;
	ORD_LIST a;
	tam = size(pl);
	if(p<1 || p>tam){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(a=pl; --p; a = a->next);
	return (a->inf);
	
}


int recover_rec(ORD_LIST pl, int k){
	if(k>0 && k<=size(pl)){
		if(k-1)
			return (pl->inf);
		else
			return recover_rec(pl->next, k-1);
	}
	else{
		printf("Error! Invalid index.\n");
		exit(2);
	}
}	
	

void remove_l(ORD_LIST *pl, int k){
	int tam;
	tam = size(*pl);
	ORD_LIST aux, aux2;
	if(k<1 || k>tam){
		printf("Error! Invalid index.\n");
		exit(1);
	}
	if(k==1){
		aux = *pl;
		*pl = (*pl)->next;
		free(aux);
	}
	else{
		for(aux = *pl; --k-1; aux = aux->next);
		aux2 = aux->next;
		aux->next = aux->next->next;
		free(aux2);
	}
}


void remove_rec(ORD_LIST *pl, int k){
	if(k>0 && k<=size(*pl)){
		if(!(k-1)){
			ORD_LIST aux;
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

int remove_rec_v(ORD_LIST *pl, int v){
	if(*pl){
		if((*pl)->inf==v){
			ORD_LIST aux;
			aux = *pl;
			*pl = (*pl)->next;
			free(aux);
			return (1);
		}
		else{
			if((*pl)->inf < v)
				return remove_rec_v(&((*pl)->next), v);
		}
	}
	else{
		return (0);
	}
}


void print(ORD_LIST pl){
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


int pertence(ORD_LIST l, int v){
	while(l){
		if(l->inf==v) return (1);
		if(l->inf > v)
		    break;
		l = l->next;
	}
	return (0); 
}


void generate(ORD_LIST *pl, int m, int n){
	if(m>n){
		printf("Error! Invalid range.\n");
		exit(6);
	}
	if(m==n){
		insert(pl, m);
	}
	else{
		generate(pl, m+1, n);
		insert(pl, m);
	}
}


void destroy(ORD_LIST *pl){
    ORD_LIST aux, aux2;
    for(aux = *pl; aux; aux = aux->next){
        aux2 = aux;
        *pl = aux->next;
        free(aux2);
    }
}







