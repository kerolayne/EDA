#include "matrizEsparca.h"
#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void inicializa_matriz(MatrizEsparsa *matriz, int linha, int coluna){

    matriz->nLinha = linha ;
    matriz->nColuna = coluna;
    inicializa_lista(&matriz->m, sizeof(Lista));
    int i;
    for (i = 0; i < linha; i++) {
      Lista l;
      inicializa_lista(&l, sizeof(EntradaMatriz));
      insereNoFim(&matriz->m, &l);
    }

}

// le na posiçao
//insere naposição

int matrix(Lista m, int l, int c){
  int i, j, x;
  Lista s;
  for (i = 0; i < l; i++) {
      inicializa_lista(&s);
      for ( j = 0; j < c ; j++) {
          printf("valor para a posiçao [%d,%d] =", i, j );
          scanf("%d", &x);
          if (x != 0) {
              insereNoFim(&componentes, &x, &j);
          }
      }
      insereNoFim(&m, &componentes, &i);
  }
}

void mostra_matriz(MatrizEsparca mat){
    Lista l
    int i, j, k, w;

    for ( i = 0; i < mat.nlinhas ; i++) {
      leNaPosiscao(&mat.m, &l, i);
      j = 0; k = 0;
      EntradaMatriz e;
      while (leNaPosiscao(&l, &e, k)!=ERRO_POSICAO_INVALIDA) {
        for (size_t w = 0; w < e.coluna; w++) {
          printf("0  ");
        }
        printf("%d\n", e.valor);
        k++;
        j = e.coluna + 1;
      }
      for (w = j; w < mat.ncoluna; w++) {
        printf("0  ");
      }
      printf("\n");
    }
}
