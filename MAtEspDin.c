#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned int *IND, N_Ele, nl, nc;
	float *VAL;
}ME;

void criate(ME*, int, int);

int assign(ME*, float, int, int);

int insert(ME*, float, int, int);

int search(ME*, int, int);

int remove(ME*, int, int);

float element(ME*, int, int);


int main(){
	char op;
	int nl, nc, i, j;
	float val;
	ME m;
	
	printf("-------------------Matriz Esparsa---------------------\nDimensão [linhas colunas]: ");
	scanf("%d %d", &m, &n);
	criate(&m, nl, nc);
	
	do{
		printf("Operações: \nA - Assign\nC - Consult\nF - Finish\n\n");
		switch(op){
			case 'A':
				printf("Value: ");
				scanf("%f", &val);
				printf("row col: ");
				scanf("%d %d", &i, &j);
				assign(&m, val, i, j);
				break;
			case 'C':
				printf("row col: ");
				scanf("%d %d", &i, &j);
				printf("M[%d][%d] = %.2f", i, j, element(&m, i, j));
				break;
			case 'F':
				printf("Thanks for try!");
		}
	}while(op!='F')
	
	return 0;
}


void criate(ME *m, int nl, int nc){
	m->nl = nl;
	m->nc = nc;
	m->N_Ele = 0;
}


void assign(ME *m, float v, int i, int j){
	int logic;
	logic = m->N_Ele<m->nl*nc?1:0;
	if(i<0 || j<0 || i>nl-1 || j>m->nc-1){
		printf("Erro! Indice invalido.");
		exit(2);
	}
	if(logic){
		if(v)
			insert(m, v, i, j);
		else{
			if(search(m, i, j))
				remove(m, i, j);
		}	
	}
	else{
		printf("Quantidade de elementos excedida.");
		exit(1);	
	}
}


int insert(ME *m, float v, int i, int j){
	int i, p, elemts;
	p = search(m, i, j);
	if(p<0){
		elemts = m->N_Ele;
		m->VAL = (float*)realloc(m->VAL, ++elemts*sizeof(float));
		m->IND = (int*)realloc(m->IND, 2*elemts*sizeof(int));
		m->VAL[elemts-1] = v;
		m->IND[(elemts-1)*2] = i;
		m->IND[(elemts-1)*2+1] = j;
		m->N_Ele = elemts;
		
	}
	else{
		m->VAL[p] = v;
	}
}


int remove(ME *m, int i, int j){
	int k, p, elemts;
	p = search(m, i, j);
	elemts = --m->N_Ele;
	for(k=p; k<elemts; k++){
		m->VAL[k] = m->VAL[k+1];
		m->IND[(k-1)*2] = m->IND[(k-1)*2];
		m->IND[(k-1)*2+1] = m->IND[(k-1)*2+1];
	}
	m->VAL = (float*)realloc(m->VAL, elemts*sizeof(float));	
}


int search(ME *m, int i, int j){
	int k, elemts;
	elemts = m->N_Ele;
	for(k=0; k<elemts; k++){
		if(m->IND[(k-1)*2]==i && m->IND[(k-1)*2+1]==j)
			return k;
	}
	return -1;
}


float element(ME *m, int i, int j){
	int p;
	p = search(m, i, j); 
	if(p<0)
		return 0;
	return m->VAL[p];
}