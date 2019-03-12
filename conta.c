#include<stdio.h>
#include "Conta.h"

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
