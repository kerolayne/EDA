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

int removeDoInicio(Lista *p, void *info){
  if(lista_vazia(*p))
    return  ERRO_LISTA_VAZIA;

  memcpy(info, p->cabeca->info, p->taminfo);

  Elemento *aux = p->cabeca;

  p->cabeca = aux->proximo;

  free(aux->info);
  free(aux);

  return 1;
}


void mostra_lista(Lista l, void (*mostra)(void *)){
    if(lista_vazia(l))
      printf("lista vazia!\n");
    else {
      printf("dados da lista:\n");
      Elemento *p = l.cabeca;
      while (p != NULL) {
        mostra(p->info);
        p = p->proximo;
      }
    }
}
