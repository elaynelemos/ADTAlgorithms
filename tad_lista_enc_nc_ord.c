/**TAD HEADER NODE THREADED AND ORDERED LIST
***User index from 1. It was processed into functions.
***by Elayne Lemos 
***elayne.l.lemos@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo * next;
}NODO;

typedef NODO * OHN_LIST;

void criate(OHN_LIST*);

int empty(OHN_LIST);

int size(OHN_LIST);

int size_l(OHN_LIST);

void insert(OHN_LIST, int);

int recover(OHN_LIST, int);

void remove_l(OHN_LIST, int);

void print(OHN_LIST);

int pertence(OHN_LIST, int);

int eh_ord(OHN_LIST);

void generate(OHN_LIST, int, int);

void destroy(OHN_LIST*);

OHN_LIST concat(OHN_LIST, OHN_LIST);



int main(){
	OHN_LIST list, list_g;
	int v, pos, m, n, op2;
	char op;
	criate(&list);
	criate(&list_g);
	printf("------------------------THREARED LIST------------------------------\n");
	do{
		printf("Operations:\nI - Insert\nE - Element\nR - Remove\nC - Concat\nG - Generate\nD - Destroy\nP - Print\nF - Finish\n");
		while(scanf("%c", &op), op==' ' || op=='\n');
		switch(op){
			case 'I':{
				printf("Value: ");
				scanf("%d", &v);
				insert(list, v);
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
			case 'C':{
			    print(concat(list, list_g));
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


void criate(OHN_LIST *pl){
	*pl = (NODO*)malloc(sizeof(NODO));
	if(!*pl){
		printf("Error! Insuficient Memory.\n");
		exit(1);
	}
	(*pl)->inf = 0;
	(*pl)->next = NULL;
}


int empty(OHN_LIST pl){
	return ((pl->inf)?0:1);
}


int size(OHN_LIST pl){
	return (pl->inf);
}

	
void insert(OHN_LIST pl, int v){
	OHN_LIST novo=NULL, aux;
	novo = (NODO*)malloc(sizeof(NODO));
	novo->inf = v;
	if(!novo){
		printf("Error! Insuficient Memory.\n");
		exit(1);
	}
	for(aux=pl; ((aux->next) && (aux->next)->inf < v); aux = aux->next);
	novo->next = aux->next;
	aux->next = novo;
	pl->inf++;
}


int recover(OHN_LIST pl, int p){
	OHN_LIST a;
	if(p<1 || p>(pl->inf)){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(a=pl->next; --p; a = a->next);
	return (a->inf);
	
}


int recover_rec(OHN_LIST pl, int k){
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
	

void remove_l(OHN_LIST pl, int k){
	OHN_LIST aux, aux2;
	if(k<1 || k>(pl->inf)){
		printf("Error! Invalid index.\n");
		exit(2);
	}
	for(aux = pl; --k; aux = aux->next);
	aux2 = aux->next;
	aux->next = aux2->next;
	pl->inf--;
	free(aux2);
}


void print(OHN_LIST pl){
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


int pertence(OHN_LIST l, int v){
	while(l){
		if(l->inf==v) return (1);
		l = l->next;
	}
	return (0); 
}


int eh_ord(OHN_LIST l){
	if(!l) return 1;
	while(l->next){
		if(l->inf > (l->next)->inf) return (0);
		l = l->next;
	}

	return (1);
}


void generate(OHN_LIST pl, int m, int n){
	if(m>n){
		printf("Error! Invalid range.\n");
		exit(3);
	}
	if(m==n){
		insert(pl, m);
	}
	else{
		generate(pl, m+1, n);
		insert(pl, m);
	}
}


void destroy(OHN_LIST *pl){
    OHN_LIST aux, aux2;
    for(aux = (*pl)->next; aux; aux = aux->next){
        aux2 = aux;
        (*pl)->next = aux->next;
        free(aux2);
    }
}


OHN_LIST concat(OHN_LIST pl, OHN_LIST pl2){
    OHN_LIST aux, aux2, include, list, li;
    criate(&list);
    li = list;
    aux2 = pl2->next;
    aux = pl->next;
    while(1){
        if(!aux2){
            aux2 = aux;
            break;
        }
        else{
            if(!aux) break;
        }
        while(aux->inf < aux2->inf){
            if((aux->inf)!=(li->inf)){
                OHN_LIST include;
                include = (NODO*)malloc(sizeof(NODO));
                if(!include){
            		printf("Error! Insuficient Memory.\n");
            		exit(1);
                }
                include->inf = aux->inf;
                include->next = li->next;
                li->next = include;
                list->inf++;
                li = li->next;
            }
            aux = aux->next;
            if(!aux){
                
            }
        }
        while(aux->inf > aux2->inf){
            if((aux2->inf)!=(li->inf)){
                OHN_LIST include;
                include = (NODO*)malloc(sizeof(NODO));
                if(!include){
            		printf("Error! Insuficient Memory.\n");
            		exit(1);
                }
                include->inf = aux2->inf;
                include->next = li->next;
                li->next = include;
                list->inf++;
                li = li->next;
            }
            aux2 = aux2->next;
            if(!aux2){
                aux2 = aux;
                break;
            }
        }
        if((aux->inf)==(aux2->inf)){
            aux2 = aux2->next;
        }
    }
    while(aux2){
        if((aux2->inf)!=(li->inf)){
            OHN_LIST include;
            include = (NODO*)malloc(sizeof(NODO));
            if(!include){
        		printf("Error! Insuficient Memory.\n");
        		exit(1);
            }
            include->inf = aux2->inf;
            include->next = li->next;
            li->next = include;
            list->inf++;
            li = li->next;
        }
        aux2 = aux2->next;
        if(!aux2){
            aux2 = aux;
            break;
        }
    }
    return (list);
}




