#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Elemento *aloca_ele(void *info, int t);

void inicializa_lista(Lista *p, int t) {
  p->cabeca = NULL;
  p->taminfo = t;
  p->num_ele = 0;
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
  p->num_ele += 1;

  return 1; //  sucesso.

}

int removeDoInicio(Lista *p, void *info){
  if(lista_vazia(*p))
    return  ERRO_LISTA_VAZIA;

  memcpy(info, p->cabeca->info, p->taminfo);

  Elemento *aux = p->cabeca;

  p->num_ele -= 1;

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

int insereNoFim(Lista *l, void *info){
  if(lista_vazia(*l))
    return insereNoInicio(l, info);
  Elemento *p = l->cabeca;
  while(p->proximo!=NULL){
    p=p->proximo;
  }
  Elemento *novo = aloca_ele(info, l->taminfo);

  if(novo == NULL)
    return 0;
  p->proximo = novo;
  novo->proximo = NULL;

  p->num_ele += 1;

  return 1;

}

Elemento *aloca_ele(void *info, int t){
  Elemento *p = malloc(sizeof(Elemento));
  if(p==NULL)
    return NULL;
  p->info = malloc(t);
  if(p->info ==   NULL){
    free(p);
    return NULL;
  }
  memcpy(p->info, info, t);
  return p;
}

int removeDoFim(Lista *l, void *info){
  if(lista_vazia(*l))
    return  ERRO_LISTA_VAZIA;

  if(l->cabeca->proximo==NULL)
    return removeDoInicio(l, info);

  Elemento *p = l->cabeca;

  while(p->proximo-> proximo!= NULL){
      p=p->proximo;
  }
  Elemento *aux = p->proximo;
  memcpy(info, aux->info,l->taminfo);

    p->num_ele -= 1;

  free(aux -> info);
  free(aux);

  p->proximo = NULL;

  return 1 ;
}

int contaElementos(Lista *l){
    int cont = 0;
    if(lista_vazia(*l))
        return  ERRO_LISTA_VAZIA;

    while(l->proximo != NULL){
        cont += 1;
    }

    printf("%d", cont);

    return 0;
}

int insereNaPosicao(Lista * l, void *info, int pos){
  if (pos < 0 || pos > l->num_ele)
    return ERRO_POSICAO_INVALIDA;

  if (pos == 0) {
    return insereNoInicio(l, info);
  }
  if (pos == l->num_ele) {
    return insereNoFim(l, info);
  }
  Elemento *p = l->cabeca;
  int cont = 0;

  while (cont < pos - 1) {
    p = p->proximo;
    cont ++;
  }
  Elemento *novo = aloca_ele(info, l->taminfo);
  if(novo == NULL)
    return 0;

  novo -> proximo = p->proximo;

  p->proximo = novo;

  l->num_ele += 1;

  return 1;
}
