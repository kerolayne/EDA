#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void inicializa_pilha(PilhaGenerica *p, int t, int c){
  p->dados =  malloc(sizeof(void *)*c);
  p->capacidade = c;
  p->topo = -1;
  p->tamInfo = t;
}
//pilha cheia /pilha vasia

int empilha(PilhaGenerica *p, void *info){
  if(pilha_cheia(*p))
    return ERRO_PILHA_CHEIA;
  p->topo++;
  p->dados[p->topo] = malloc(p->tamInfo);

  memcpy(p->dados[p->topo], info, p->tamInfo);

  return 1;
}

int desempilha(PilhaGenerica *p, void *info ){
  if(pilha_vazia(*p))
    return ERRO_PILHA_VAZIA;
  memcpy(info, p->dados[p->topo], p->tamInfo);
  free(p->dados[p->topo]);
  p->topo--;

  return 1;
}

void mostra_pilha(PilhaGenerica p, void(*mostra)(void*)){
  if (pilha_vazia(p)) {
    printf("Pilha vazia\n");
  }else{
    printf("Dados da pilha:\n");
    int i;
    for (i = 0; i <= p.topo; i++) {
      mostra(p.dados[i]);
    }
  }
}

void desaloca(PilhaGenerica *p){
  int i;
  for(i = 0; i <= p->topo; i++){
    free(p->dados[i]);
  }
  free(p->dados);
}
int pilha_vazia(PilhaGenerica p){
  if(p.topo == -1)
    return 1;
  else
    return 0;
}
int pilha_cheia(PilhaGenerica  p){
  return p.topo == p.capacidade -1;
}
