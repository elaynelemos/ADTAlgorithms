#include <stdio.h>

typedef struct{
	int num, den;
}racional;

void inicializar_racional(int, int, racional*);

void reduzir_racional(racional*);

int main(){
	int num, den;
	racional r1;
	
	scanf("%d/%d", &num, &den);
	inicializar_racional(num, den, &r1);
	reduzir_racional(&r1);
	
	return 0;
}

void inicializar_racional(int n, int d, racional *r){
	r->num = n;
	r->den = d;
}

void reduzir_racional(racional *r){
	int n, d, q, rst;
	n = r->num;
	d = r->den;
	if(n>d){
		while(
	}
}