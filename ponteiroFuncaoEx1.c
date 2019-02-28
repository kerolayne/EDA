#include<stdlib.h>
#include<stdio.h>

int soma(int x, int y){
	return x + y;
}

int sub(int x, int y){
	return x - y;
}

int main(int argc, char const *argv[]) {
	int a, b, op;

	printf("digite dois numeros:\n");
	scanf("%d %d", &a, &b );

	printf("1-SOMA\n 2-SUBTRACAO\n");
	scanf("%d", &op );
/*
	switch (op) {
		case 1:
			printf("soma: %d\n", soma(a,b) );
		break;

		case 2 :
			printf("subtracao:%d\n", sub( a, b) );
		break;
	}
	*/

	//barra forcada
	/*
	if(op =! 1 || op =! 2){
		printf("ERRRROOOUUUUU!!!!!!!!!!!!!!!!\n");
		return 0;

	*/
	}

	int (*p)(int, int);

	switch (op) {
		case 1:
			p = soma;
		break;

		case 2 :
			p = sub;
		break;
}
		printf("Resultado: %d\n", p(a,b));

	return 0;
}
