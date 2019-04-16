#include "Pilha.h"
#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  Fila f1;

  inicializa_fila(&f1, 50);
  int x;

  do{
    printf("digite um numero(0 p/sair!!!): \n");

    scanf("%d", &x );
    if(x!=0)
      inserir(&f1,x);
  }while(x!=0 && !fila_cheia(f1));

  mostra_fila(f1);

  Pilha p1;

  inicializa_pilha(&p1, 50);

  while(!fila_vazia (f1){
    remover(&f1, &x);
    empilha(&p1,x);
  }
  while(!pilha_vazia(p1)){
    desenpilha(&p1, &x);
    inserir(&f1, x);
  }
  mostra_fila(f1);

  desaloca_fila(&f1);

  desaloca_pilha(&p1);

  return 0;
}
