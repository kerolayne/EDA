#include "lista.h"
#include <stdio.h>

void mostra_float(void *x);

int main(int argc, char const *argv[]) {
  Lista l1;

  float x = 9;

  inicializa_lista(&l1, sizeof(float));

  insereNoInicio(&l1, &x);
  x = 3;

  //removeDoInicio(&l1, &x);

  mostra_lista(l1, mostra_float);

  insereNoFim(&l1, &x);


  float x = 16;

  insereNaPosicao(&l1, &x, 2);



  mostra_lista(l1, mostra_float);



  return 0;
}


void mostra_float(void *x){
  float *p = x;
  printf("%.1f\n", *p);
}
