#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inicializa_lista(Lista *p, int c) {
  p->cabeca = NULL;
  P->taminfo = t;
}

int lista_vazia(Lista l){
  return l.cabeca == NULL;
}

int insereNoInicio(Lista *p, void *info){
  Elemento *novo = malloc(sizeof(Elemento));
  if( novo == NULL )
    return 0;
  novo->info=malloc(p->taminfo);
  if(novo->info == NULL){
    free(novo);
    return 0;
  }
  memcpy(novo->info, info, p->taminfo);
  novo->proximo = p->cabeca;
  p->cabeca = novo;
  return 1; //  sucesso.
}
