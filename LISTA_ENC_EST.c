#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct{
	float inf;
	int next;
}NODO;

typedef struct{
	int ind_pri_ele;
	int ind_nodo_livre;
	NODO elementos[max];
}LISTA_ENC_EST;

void criate_list(LISTA_ENC_EST*);
void insert(LISTA_ENC_EST*, float, int);
void remove(LISTA_ENC_EST*, float);
int empty(LISTA_ENC_EST*);
int length(LISTA_ENC_EST*);
int recover(LISTA_ENC_EST*, float);

int main(){
	LISTA_ENC_EST list;
	float v;
	int p, aux;
	char op;
	criate(&list);
	do{
		printf("--------------LIST [max = %d]-----------------\nI - Insert\nR - Remove\nE - Element\nF - Finish\n", max);
		switch(op){
			case 'I':{
				printf("Value: ");
				scanf("%f", &v);
				printf("Position: ");
				scanf("%d", &p);
				insert(&list, v, p);
				break;
			}
			case 'R':{
				printf("Position: ");
				scanf("%d", &p);
				remove(&list, p);
				break;
			}
			case 'E':{
				printf("Position: ");
				scanf("%d", &p);
				printf("Value[%d] = %.2f\n", p, list->elementos[recover(&list, p)].inf);
				break;
			}
			case 'F': printf("Thanks for try!");
	}while(op!='F');
}


void criate_list(LISTA_ENC_EST *l){
	int i;
	l->ind_pri_ele = -1;
	l->ind_nodo_livre = 0;
	for(i=0; i<max-1; i++){
		l->elementos[i].next = i+1;
	}
	l->elementos[i].next = -1;
}


int empty(LISTA_ENC_EST *l){
	return (l->ind_pri_ele<0?1:0);
}


int length(LISTA_ENC_EST *l){
	int i, total;
	i=l->ind_pri_ele;
	total = 0;
	while(1){
		if(l->elementos[i].next>=0){
			i = l->elementos[i].next;
			total++;
		}
		else
			return total;
	}
}


void insert(LISTA_ENC_EST *l, float v, int p){
	int i, k, next, livre;
	livre = l->ind_nodo_livre;
	if(livre<0){
		printf("Erro! Lista totalmente preenchida.");
		exit(1);
	}
	if(p>max || p<1){
		printf("Erro! Posicao fora do intervalo.");
		exit(2);
	}
	if(p==1){
		i = l->ind_pri_ele;
		k = l->elementos[livre].next;
		l->elementos[livre].inf = v;
		elementos[livre].next = i;
		l->ind_nodo_livre = k;
		l->ind_pri_ele = livre;
	}
	else{
		if(p==max){
			l->elementos[livre].inf = v;
		}
		else{
			l->elementos[livre].inf = v;
			for(i=l->ind_pri_ele; p-1; p--){
				if(p==2){
					l->elementos[i].next = livre;
				}
				i = l->elementos[i].next;
			}
			next = i;
			l->ind_nodo_livre = l->elementos[livre].next;
			l->elementos[livre].next = next;
		}	
	}
}



int recover(LISTA_ENC_EST *l, int p){
	int i, p;
	i=l->ind_pri_ele;
	while(--p){
		i = l->elementos[i].next;
		if(i==-1){p--; break;}
	}
	if(!p){
		return i;
	}
}


int remove(LISTA_ENC_EST *l, int p){
	int i, livre, aux, prox;
	aux = recover(l, p);
	livre = l->ind_nodo_livre;
	prox = l->elementos[aux].next;
	if(aux!=-1){
		if(p==1){
			l->ind_pri_ele = prox;
			l->elementos[aux].next = livre;
			l->ind_nodo_livre = aux;
		}
		else{
			for(i=ind_pri_ele; --p-1; i = l->elementos[i].next);
			l->elementos[i].next = prox;
			l->elementos[aux].next = livre;
			l->ind_nodo_livre = aux;
		}
	}
	else{
		printf("Indice invalido.");
		exit(3);
	}
}



















