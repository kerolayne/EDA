#include<stdlib.h>
#include<stdio.h>
#include "Conta.h"



int main(int argc, char const *argv[]) {
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
