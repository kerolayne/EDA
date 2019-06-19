#include "matrizEsparca.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    int o, l1, c1, l2, c2;

    Lista p1, p2;

    inicializa_lista(&p1, sizeof(Lista));
    inicializa_lista(&p2, sizeof(Lista));

    do {
        printf("\nSelecione a operação:\n");
        printf("1. criar matriz 1\n");
        printf("2. criar matriz 2\n");
        printf("3. somar matriz\n");
        printf("4. multiplica matriz\n");
        printf("5. mostra matriz 1\n");
        printf("6. mostra matriz 2\n");
        printf("7. mostra matriz resultado\n");
        printf("0. sair \n");

        scanf("%d", &o);

        switch (o) {
          case 1:

          //solicita o tamanho do matriz
              printf("Quantas linhas e quantas colunas???\n");
              scanf("%d", &l1);
              scanf("%d", &c1);
              //cria matriz 1
              matriz(p1, l1, c1);
          break;

          case 2:

              //solicita o tamanho do matriz
              printf("Quantas linhas e quantas colunas???\n");
              scanf("%d", &l2);
              scanf("%d", &c2);
              //cria matriz 2
              matriz(p2, l2, c2);

          break;

          case 3:
            //soma matriz ;
          break;

          case 4:
            //multiplica matriz;
          break;

          case 5:
            // mostra matriz ;
              mostra_matriz(p1, mostra_int, l1, c1);

          break;

          case 6:
          // mostra matriz ;
              mostra_matriz(p2, mostra_int, l2, c2);

          break;
    /*
          case 7:
          // mostra matriz ;

              mostra_matriz()

          break;
          */
        }

        if (o > 7) {
          printf("operação não encontrada, tente novamente!!!!\n");
        }
  } while(o!=0);
  return 0;
}
