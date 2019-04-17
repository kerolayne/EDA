#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

void inicializa_fila(FILA *p, int c) {
  p-> dados = malloc(sizeof(int)*c);
  p->capacidade = c;
  p->inicio = p->fim = p->num_ele = 0;
}

int fila_vazia(Fila f){
  return f.num_ele == 0;
}

int fila_cheia(Fila f){
  return f.num_ele == f.capacidade;
}

int inserir(Fila *p, int info){
  if (fila_cheia(*p))
    return ERRO_FILA_CHEIA;
  p->num_ele++;
  p->dados[p->fim] = info;
  if(p->fim == p->capacidade -1)
    p->fim = 0;
  else
    p->fim ++;
  return 1;
}

int remover(Fila *p, int *info){
  if(fila_vazia(*p))
    return ERRO_FILA_VAZIA;
  p->num_ele --;
  *info = p->dados[p->inicio];
  if(p->inicio == p->capacidade -1)
    p->inicio = 0;
  else
    p->inicio ++;
  return 1;
}
