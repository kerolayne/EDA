#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
STRUCT

*HETEROGENEAS
*VALORES SAO ACESSADOS ATRAVES DOS IDENTIFICADORES(NOMES/VARIAVEIS) DOS CAMPOS.

*/

typedef struct conta{
    int num;
    float saldo;
    char cliente[30];
}Cont;

void mostraConta(Cont c, int k) {
    printf("DADOS DA CONTA(%d):\n", k + 1);
    printf("NUM:%d\nSALDO:R$%.2f\nCLIENTE:%s\n\n", c.num, c.saldo, c.cliente  );
}
void leConta(Cont *p, int k) {
    printf("dados da conta %d:\n", k + 1 );
    scanf("%d %f %s",&p->num, &p->saldo, p->cliente );
}
/*
¬ &p->cliente: isso deve ser usado em ponteiros para struct
¬ c.cliente: isso se usa quando se tem apenas uma struct.
*/

int main(int argc, char const *argv[]) {
    /*Cont v[5];
    int i;*/
    int i, n;

    printf("quantas contas?");

    scanf("%d", &n);

    Cont *v = malloc(sizeof(Cont)*n);

    for(i = 0; i < n; i ++){
        leConta(&v[i], i);

    }
    for ( i = 0; i < n; i++) {
        mostraConta(v[i], i);

    }
    free(v);
    return 0;
}
