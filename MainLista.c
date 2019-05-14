#include "LISTA.h"
#include <stdio.h>


void mostra_float(void *x);

int compara_float(void *x, void *y);

int main(int argc, char const *argv[]) {
  Lista l1;

  float x, y;

  inicializa_lista(&l1, sizeof(float));

  printf("digite um valor");
  scanf("%f", &x);

  insereNoInicio(&l1, &x);

  printf("digite um valor");
  scanf("%f", &x);

  //removeDoInicio(&l1, &x);

  mostra_lista(l1, mostra_float);

  insereNoFim(&l1, &x);


  printf("digite um valor");
  scanf("%f", &x);

  insereNaPosicao(&l1, &x, 2);

  //removeDaPosicao(&l1, &y, 2);

  insereEmOrdem(&l1, &x, compara_float);


  mostra_lista(l1, mostra_float);



  return 0;
}


int compara_float(void *x, void *y){
  float *a = x, *b = y;
  if(*a > *b)
    return 1;
  if (*a < *b ) {
    return -1;
  }
}

void mostra_float(void *x){
  float *p = x;
  printf("%.1f\n", *p);
}
