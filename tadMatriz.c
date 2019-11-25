#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int nl, nc, *elementos;
}MATRIZ;

int criar_matriz(int, int, MATRIZ*);

void inicializar_matriz(MATRIZ*);
void imprimir_matriz(MATRIZ*);
/*
int somar_matriz(MATRIZ*, MATRIZ*, MATRIZ*);
int subtrair_matriz(MATRIZ*, MATRIZ*, MATRIZ*);
int multiplicar_matriz(MATRIZ*, MATRIZ*, MATRIZ*);
*/

int main(){
	int nl, nc;
	MATRIZ m1;
	
	printf("Forneca o tamanho da matriz: ");
	scanf("%d %d", &nl, &nc);
	printf("%d", criar_matriz(nl, nc, &m1));
	return 0;
}

int criar_matriz(int nl, int nc, MATRIZ *m1){
	int i, j;
	m1->elementos = (int*)malloc(sizeof(int)*nl*nc);
	if(!m1->elementos){
		printf("Erro! Nao foi possivel reservar o espaco requerido na memoria");
		return 1;
	}
	m1->nl = nl;
	m1->nc = nc;
	for(i=0; i<nl; i++){
		for(j=0; j<nc; j++){
			m1->elementos[i*nc+j] = 0;
		}
	}
	return 0;
}

void inicializar_matriz(MATRIZ *m){
	int i, j;
	for(i=0; i<m->nl; i++){
		for(j=0; j<m->nc; j++){
			printf("Matriz[%d][%d]", i+1, j+1);
			scanf("%d", m->elementos+i*m->nc+j);
		}
	}
}