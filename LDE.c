#include "LDE.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EleDuplo *aloca_ele(void *info, int t);

int insereNoInicio(LDE *p, void *info){
  EleDuplo *novo = aloca_ele(info, p->tamInfo);
  if( novo == NULL )
    return 0;

  novo->suc = p->cabeca;
  p->cabeca = novo;
  novo->ant = NULL;
  if (novo->suc != NULL) {
    novo->suc->ant = novo;
  }
  p->num_ele ++;

  return 1; //  sucesso.

}

int lista_vazia(LDE l){
  return l.cabeca == NULL;
}

int removeDoInicio(LDE *p, void *info){
  if(lista_vazia(*p))
    return  ERRO_LISTA_VAZIA;

  memcpy(info, p->cabeca->info, p->tamInfo);

  EleDuplo *aux = p->cabeca;

  p->cabeca = aux->suc;

  free(aux->info);
  free(aux);


  if(p->cabeca != NULL){
    p->cabeca->ant = NULL;
  }

  p->num_ele --;
  return 1;
}



EleDuplo *aloca_ele(void *info, int t){
  EleDuplo *p = malloc(sizeof(EleDuplo));
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

int insereNoFim(LDE *l, void *info){
  if(lista_vazia(*l))
    return insereNoInicio(l, info);
  EleDuplo *p = l->cabeca;
  while(p->suc!=NULL){
    p=p->suc;
  }
  EleDuplo *novo = aloca_ele(info, l->tamInfo);

  if(novo == NULL)
    return 0;
    
  p->suc = novo;
  novo->suc = NULL;

  novo->ant = p;

  l->num_ele ++;

  return 1;

}
