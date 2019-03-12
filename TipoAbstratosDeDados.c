#include<stdlib.h>
#include<stdio.h>

#define SALDO_INSUFICIENTE -1;

typedef struct{
	int numero;
	float saldo; 
}Conta;

void inicializaConta( Conta *p, int n , float s){
	p-> numero = n;
	p-> saldo = s;
}
void mostraConta(Conta c){
	printf("num:%d\nSaldo:%.2f\n\n",c.numero, c.saldo);
}

int saque(Conta *p, float v){
	if (v > p-> saldo) {
		return SALDO_INSUFICIENTE;
	}
	p->saldo -= v;

	return 1;
}

void deposito(Conta *p, float v){
	p->saldo += v;
}

int int main(int argc, char const *argv[]) {
	Conta a, b;


	inicializaConta(&a, 123,1000);
	inicializaConta(&b, 456,500);

	mostraConta(a);
	float valor = 100;
	if(saque(&a, valor) == SALDO_INSUFICIENTE){
		printf("SALDO É INSUFICIENTE\n");
	}

	mostraConta(a);

	mostraConta(b);

	deposito(&b, 200);
	mostraConta(b);
	
	return 0;
}
