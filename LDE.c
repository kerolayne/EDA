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

int insereNaPosicao(LDE * l, void *info, int pos){
  if (pos < 0 || pos > l->num_ele)
    return ERRO_POSICAO_INVALIDA;

  if (pos == 0) {
    return insereNoInicio(l, info);
  }
  if (pos == l->num_ele) {
    return insereNoFim(l, info);
  }
  EleDuplo *p = l->cabeca;
  int cont = 0;

  while (cont < pos - 1) {
    p = p->suc;
    cont ++;
  }
  EleDuplo *novo = aloca_ele(info, l->tamInfo);
  if(novo == NULL)
    return 0;

  novo->suc = p->suc;

  p->suc = novo;

  novo->ant = p;
  novo->suc->ant = novo;

  l->num_ele += 1;

  return 1;
}

int removeDaPosicao(LDE *l, void *info, int pos){
    if(lista_vazia(*l))
        return ERRO_LISTA_VAZIA;

    if (pos < 0 || pos >= l->num_ele)
      return ERRO_POSICAO_INVALIDA;

    if (pos == 0) {
      return removeDoInicio(l, info);
    }
    if (pos == l->num_ele) {
      return removeDoFim(l, info);
    }

    EleDuplo *p = l->cabeca;
    int cont = 0;

    while(cont < pos-1){
        p = p->suc;
        cont ++;
    }
    EleDuplo *aux = p->suc;

    p->suc = aux->suc;
    p->suc->ant = p;

    memcpy(info, aux->info, l->tamInfo);

    free(aux->info);
    free(aux);

    l->num_ele--;

    return 1;
}
