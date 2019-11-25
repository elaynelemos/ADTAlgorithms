#include <stdio.h>

typedef struct{
	int num, den;
}racional;

void initRacional(int, int, racional*);

void soma_racionais(racional*, racional*, racional*);

void equi_racional(racional*);

int main(){
	racional a, b, c;
	int num, den;
	printf("Digite numerador e denominador do primeiro racional: ");
	scanf("%d %d", &num, &den);
	initRacional(num, den, &a);
	printf("Digite numerador e denominador do segundo racional: ");
	scanf("%d %d", &num, &den);
	initRacional(num, den, &b);
	soma_racionais(&a, &b, &c);
	equi_racional(&c);
	
	printf("\nRacional resultante = %d / %d\n", c.num, c.den);
	
	return 0;
	
}

void initRacional(int n1, int n2, racional *a){
	a->num = n1;
	a->den = n2;
}

void soma_racionais(racional *a, racional *b, racional *c){
	int n1, n2, d1, d2, num, den, aux, d11;
	n1 = a->num;
	n2 = b->num;
	d1 = a->den;
	d2 = b->den;
	if(d1>d2){
		aux = d1;
		d1 = d2;
		d2 = aux;
		aux = n1;
		n1 = n2;
		n2 = aux;
	}
	d11 = d1;
	if(d2%d1==0){
		den = d2;
		num = d2/d1*n1 + n2;
	}
	else{
		for(aux = 2, den=1; aux<d1; aux++){
			while(d1%aux==0 && d2%aux==0){
				den*=aux;
				d1/=aux;
				d2/=aux;
			}
		}
		den *= d1*d2;
		if(d11==a->den){
			d1 = a->den;
			d2 = b->den;
		}
		else{
			d1 = b->den;
			d2 = a->den;
			
		}
		num = den/d1*n1 + den/d2*n2;
	}
	c->num = num;
	c-> den = den;
}


void equi_racional(racional *r){
	int n, d, aux;
	n = r->num;
	d = r->den;
	if(n>d){
		if(n%d==0){
			n/=d;
			d=1;
		}
		else{
			for(aux=2; aux<d; aux++){
				while(n%aux==0 && d%aux==0){
					n/=aux;
					d/=aux;
				}
			}
		}
	}
	else{
		if(d==n){
			d = n = 1;
		}
		else{
			if(d%n==0){
				d/=n;
				n=1;
			}
			else{
				for(aux=2; aux<n; aux++){
					while(n%aux==0 && d%aux==0){
						n/=aux;
						d/=aux;
					}
				}
			}
		}
	}
	r->num = n;
	r->den = d;
	
}















































