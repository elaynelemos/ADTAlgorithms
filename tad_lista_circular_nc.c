/**TAD HEADER NODE CIRCLED LIST
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo * next;
}NODO;

typedef NODO * HNC_LIST;

void criate(HNC_LIST*);

int empty(HNC_LIST);

int size(HNC_LIST);

int size_l(HNC_LIST);

void insert(HNC_LIST, int, int);

int recover(HNC_LIST, int);

void remove_l(HNC_LIST, int);

void print(HNC_LIST);

int pertence(HNC_LIST, int);

int eh_ord(HNC_LIST);

void generate(HNC_LIST, int, int);

void destroy(HNC_LIST);


int main(){
	HNC_LIST list, list_g;
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
			            destroy(list_g);
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


void criate(HNC_LIST *pl){
	*pl = (NODO*)malloc(sizeof(NODO));
	if(!*pl){
		printf("Error! Insuficient Memory.\n");
		exit(1);
	}
	(*pl)->inf = 0;
	(*pl)->next = NULL;
}

int empty(HNC_LIST pl){
	return ((pl->inf)?0:1);
}


int size(HNC_LIST pl){
	return (pl->inf);
}

	
void insert(HNC_LIST pl, int v, int k){
	HNC_LIST novo=NULL, aux;
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
		novo->next = pl;
	}else{
		for(aux=pl; k>1; k--, aux = aux->next);
		novo->next = aux->next;
		aux->next = novo;
	}
	pl->inf++;
}


int recover(HNC_LIST pl, int k){
	HNC_LIST a;
	if(k<1 || k>(pl->inf)){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(a=pl->next; --k; a = a->next);
	return (a->inf);
	
}


int recover_rec(HNC_LIST pl, int k){
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
	

void remove_l(HNC_LIST pl, int k){
	HNC_LIST aux, aux2;
	if(k<1 || k>(pl->inf)){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	if(pl->inf==1){
	    aux = pl->next;
	    free(aux);
	    pl->next = NULL;
	}
	else{
    	for(aux = pl; k>1; k--, aux = aux->next);
    	aux2 = aux->next;
    	aux->next = aux2->next;
    	free(aux2);
	}
	pl->inf--;
}


void print(HNC_LIST pl){
	printf("LIST = { ");
	if(pl->inf){
	    HNC_LIST a = pl;
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


int pertence(HNC_LIST pl, int v){
    if(pl){
        HNC_LIST a = pl;
    	while(pl->next!=a){
    		pl = pl->next;
    		if(pl->inf==v) return (1);
    	}
    }
	return (0); 
}


int eh_ord(HNC_LIST pl){
	if(!pl || (pl->inf)==1) return 1;
	else{
	    HNC_LIST a = pl;
    	while(pl->next!=a){
    	    pl = pl->next;
    		if(pl->inf > (pl->next)->inf) return (0);
    	}
	}
	return (1);
}


void generate(HNC_LIST pl, int m, int n){
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


void destroy(HNC_LIST pl){
    HNC_LIST aux, aux2, list;
    if(pl->inf){
		if(pl->inf==1){
		    aux = pl->next;
		    free(aux);
		}
		else{
		    list = pl;
		    for(aux = pl->next; aux!=list; aux = aux->next){
		        aux2 = aux;
		        free(aux2);
		    }
		}
    }
}




