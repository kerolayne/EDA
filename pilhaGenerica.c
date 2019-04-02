#include <string.h>
#include "pilhaGenerica.h"

void inicializa_pilha(PilhaGenerica *p, int t, int c){
  p->dados =  malloc(sizeof(void *)*c);
  p->capacidade = c;
  p->topo = -1;
  p->tamInfo = t;
}
//pilha cheia /pilha vasia

int empilha(PilhaGenerica *p, void *emp){
  if(pilha_cheia(*p))
    return ERRO_PILHA_CHEIA;
  p->topo++;
  p->dados[p->topo] = molloc(p->tamInfo);

  memcpy(p->dados[p->topo], info, p->tamInfo);

  return 1;
}

int desempilha(PilhaGenerica *p, void *info ){
  if(pilha_vazia(*p))
    return ERRO_PILHA_VAZIA;
  memcpy(info, p->dados[p->topo], p->taminfo);
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

void desaloca_pilha(PilhaGenerica *p){
  int i;
  for(i = 0; i <= p->topo; i++){
    free(p->dados[i]);
  }
  free(p->dados);
}
