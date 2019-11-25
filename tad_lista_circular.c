/**TAD  CIRCLED LIST
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo * next;
}NODO;

typedef NODO * C_LIST;

void criate(C_LIST*);

int empty(C_LIST);

int size(C_LIST);

int size_l(C_LIST);

void insert(C_LIST*, int, int);

void insert_rec(C_LIST*, int, int);

 int recover(C_LIST, int);

void remove_l(C_LIST*, int);

void remove_rec(C_LIST*, int);

void print(C_LIST);

int pertence(C_LIST, int);

int eh_ord(C_LIST);

void generate(C_LIST*, int, int);

void destroy(C_LIST*);


int main(){
	C_LIST list, list_g;
	int v, op2, pos, m, n;
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
			default: printf("Invalid option.\n");
		}
	}while(op != 'F');
	
	return 0;
} 	


void criate(C_LIST *pl){
	*pl = NULL;
}

int empty(C_LIST pl){
	return (!pl);
}

int size(C_LIST pl){
	int tam;
	C_LIST list = pl;
	if(list){
	    tam = 1;
    	while(pl->next!=list){
    		pl = pl->next;
    		tam++;
    	}
    	return tam;
	}
	return (0);
}


int size_rec(C_LIST pl, C_LIST aux){
    if(pl){
        if(pl==(aux->next)){
            return (1);
        }
        else{
            return (1+size_rec(pl, aux->next));
        }
    }
    else{
        return (0);
    }
}


void insert(C_LIST *pl, int v, int k){
	int tam;
	C_LIST novo=NULL, aux;
	tam = size(*pl);
	if(k<1 || k>tam+1){
		printf("Error! Invalid index.\n");
		exit(1);
	}
	novo = (NODO*)malloc(sizeof(NODO));
	novo->inf = v;
	if(!novo){
		printf("Error! Insuficient Memory.\n");
		exit(3);
	}
	if(!(*pl)){
	    novo->next = novo;
	    *pl = novo;
	}
	else{
    	aux = *pl;
    	if(k==tam+1){
    	    *pl = novo;
    	}
    	for(; k>1; k--, aux = aux->next);
    	novo->next = aux->next;
    	aux->next = novo;
	}
	
}


int recover(C_LIST pl, int k){
	int tam;
	C_LIST a;
	tam = size(pl);
	if(k<1 || k>tam){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(a=pl->next; --k; a = a->next);
	return (a->inf);
	
}


void remove_l(C_LIST *pl, int k){
	int tam, list=k;
	tam = size(*pl);
	C_LIST aux, aux2;
	if(k<1 || k>tam){
		printf("Error! Invalid index.\n");
		exit(1);
	}
	if(tam==1){
	    free(*pl);
	    *pl = NULL;
	}else{
    	for(aux = *pl; --k; aux = aux->next);
    	aux2 = aux->next;
    	aux->next = aux2->next;
    	if(list==tam){
    	    *pl = aux;
    	}
    	free(aux2);
	}
}


void print(C_LIST pl){
	int i, tam;
	c_LIST last = pl;
	tam = size(pl);
	printf("LIST = { ");
	if(pl){
    	while(pl->next!=last){
    	    pl = pl->next;
    		printf("%d, ", pl->inf);
    	}
    	printf("%d ", (pl->next)->inf);
	}
	printf("}\n");
}


int pertence(C_LIST l, int v){
    C_LIST aux = l;
	while(l && l->next!=aux){
		if(l->inf==v) return (1);
		l = l->next;
	}
	return (0); 
}


int eh_ord(C_LIST l){
	if(!l) return 1;
	else{
	    C_LIST aux = l;
    	while(l && l->next!=aux){
    		if(l->inf > (l->next)->inf) return (0);
    		l = l->next;
    	}
    	return (1);
	}
}


void generate(C_LIST *pl, int m, int n){
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


void destroy(C_LIST *pl){
    C_LIST aux, aux2;
    int tam = size(*pl);
    for(aux = *pl; --tam; aux = aux->next){
        aux2 = aux;
        *pl = aux->next;
        free(aux2);
    }
    free(aux);
    *pl = NULL;
}










