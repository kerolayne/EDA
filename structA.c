#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
STRUCT

*HETEROGENEAS
*VALORES SAO ACESSADOS ATRAVES DOS IDENTIFICADORES(NOMES/VARIAVEIS) DOS CAMPOS.

*/

typedef struct conta/*opcional*/{
    int num;
    float saldo;
    char cliente[30];
}Cont;

int main(int argc, char const *argv[]) {
    Cont x,y;

    x.num = 123;
    x.saldo = 1000;

    strcpy(x.cliente, "Maria");

    printf("num:%d\nsaldo:R$%.2f\nCliente:%s\n", x.num, x.saldo, x.cliente);

    printf("Digite os valores de y\n");

    scanf("%d %f %s", &y.num, &y.saldo, y.cliente);

    printf("num:%d\nsaldo:R$%.2f\nCliente:%s\n", y.num, y.saldo, y.cliente);

    x=y;//funciona x recebe y

    printf("X:\nnum:%d\nsaldo:R$%.2f\nCliente:%s\n", x.num, x.saldo, x.cliente);
    
    printf("tamanho da struct em bites: %ld\n",sizeof(Cont) );
    return 0;
}
