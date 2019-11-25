#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned int *IND, N_Ele, nl, nc;
	float *VAL;
}ME;

void criate(ME*, int, int);

void assign(ME*, float, int, int);

int insert(ME*, float, int, int);

int search(ME*, int, int);

int remove(ME*, float);

int main(){
	int nl, nc;
	float val;
	ME m;
	
	printf("-------------------Matriz Esparsa---------------------\nDimensão [linhas colunas]: ");
	scanf("%d %d", &m, &n);
	criate(&m, nl, nc);
	
	
	return 0;
}

void assign(ME *m, float v, int i, int j){
	int logic;
	logic = m->N_Ele<m->nl*nc?1:0;
	if(logic){
		if
		insert(m, v, i, j);
	
	
}

