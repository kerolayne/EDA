#include "LISTA.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int l,c,i,j, x;

  printf("Quantas linhas e quantas colunas?\n");
  scanf("%d %d", &l, &c);

  Lista m;

  inicializa_lista(&m, sizeof(Lista));

  Lista sub;
  for(i = 0; i < l; i++){
    inicializa_lista(&sub, sizeof(int));
    for (j = 0; j < c; j++) {
      printf("m[%d,%d] =", i, j );
      scanf("%d", &x);
      insereNoFim(&sub, &x);
    }
    insereNoFim(&m, &sub);
  }
  for (i = 0; i < l; i++) {
    leNaPosiscao(&m, &sub, i);
    for ( j = 0; j < c; j++) {
      leNaPosiscao(&sub, &x, j);
      printf("%4d", x);
    }
    printf("\n");
  }
  for (i = 0; i < l; i++) {
    leNaPosiscao(&m, &sub, i);
    desaloca_lista(&sub);
  }
  desaloca_lista(&m);
  
  return 0;
}
