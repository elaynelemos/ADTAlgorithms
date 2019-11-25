/**
***TAD_LIST_ESTATICA
***Indices em C iniciam em 0, 
***valores fornecidos pelo usuario tratados.*/

#include <stdio.h>
#include <stdlib.h>
#define max 10


typedef struct {
	int N, val[max];
}LIST;

void criate(LIST*);

void print(LIST*);

void generate(LIST*, int, int);

int empty(LIST*);

int size(LIST*);

int insert(LIST*, int, int);

int recover(LIST*, int);

int belong(LIST*, int);

int eh_ord(LIST*);

int remove_l(LIST*, int);


int main(){
	char op;
	int v, p;
	LIST list, L2;
	printf("--------------------------STATIC LIST---------------------------------\n");
	criate(&list);
	criate(&L2);
	do{
		printf("Operations: \nI - Insert\nP - Print\nR - Remove\nF - Finish\n");
		while(scanf("%c", &op), op=='\n' || op==' ');
		switch(op){
			case 'I':{
				printf("Value: ");
				scanf("%d", &v);
				printf("Position: ");
				scanf("%d", &p);
				if(!insert(&list, v, p)){
					printf("Error! Insert.");
					exit(1);
				}
				break;
			}
			case 'P':{		
				print(&list);
				break;
			}
			case 'R':{
				printf("Position: ");
				scanf("%d", &p);
				if(!remove_l(&list, p)){
					printf("Error! Remove.");
					exit(4);
				}
				break;
			}
			case 'F': printf("Thanks for try!");			
		}
	}while(op!='F');
	
	return 0;
}


void criate(LIST *l){
	l->N = 0;
}


int empty(LIST *l){
	return (l->N==0);
}


int size(LIST *l){
	return l->N;
}


int insert(LIST *l, int v, int p){
	int tam, i;
	tam = size(l);
	if(tam==max){
		printf("Error! Elements limit exceeded.");
		exit(3);
	}
	if(p>tam+1 || p<1){
		printf("Error! Invalid index.");
		exit(2);
	}
	p--;
	if(p<=tam){
		for(i=tam-1; i>=p; i--){
			l->val[i+1] = l->val[i];
		}
	}
	l->val[p] = v;
	l->N++;
}


int recover(LIST *l, int p){
	int i, tam;
	tam = size(l);
	if(p>tam || p<1){
		printf("Error! Invalid index.");
		exit(2);
	}
	return l->val[p-1];
}


int remove_l(LIST *l, int p){
	int i, tam;
	tam = size(l);
	if(p>tam+1 || p<1){
		printf("Error! Invalid index.");
		exit(2);
	}
	p--;
	for(i=p; i<tam-1; i++){
		l->val[i] = l->val[i+1];
	}
	l->N--;
}
	
	
void print(LIST *l){
	int i, tam;
	tam = size(l);
	printf("LIST = { ");
	for(i=0; i<tam; i++){
		if(i==tam-1) {
			printf("%d ", recover(l, i+1));
			break;
		}
		printf("%d, ", recover(l, i+1));
	}
	printf("}\n");
}
	

int belong(LIST *l, int v){
	int i, tam;
	tam = size(l);
	for(i=0; i<tam; i++){
		if(l->val[i]==v) return 1;
	}
	return 0;
}


int eh_ord(LIST *l){
	int i, tam;
	tam = size(l);
	for(i=0; i<tam-1; i++){
		if(l->val[i] > l->val[i+1]) return 0;
	}
	return 1;
}


void generate(LIST *l, int m, int n){
	l->N = n-m;
	if(m>n){
		printf("Error! Invalid range.");
		exit(6);
	}
	if(m==n){
		insert(l, m, 1);
	}
	else{
		generate(l, m+1, n);
		insert(l, m, 1);
	}
}	


