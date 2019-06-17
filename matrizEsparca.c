#include "matrizEsparca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Elemento *aloca_ele(int *indice ,void *info, int t);

void inicializa_lista(Lista *p, int t) {
  p->cabeca = NULL;
  p->taminfo = t;
  p->num_ele = 0;
}

int matriz_vazia(Lista l){
  return l.cabeca == NULL;
}

int insereNoInicio(Lista *p, void *info, int *indice){
  Elemento *novo = malloc(sizeof(Elemento));
  if( novo == NULL ){
    return 0;
  }
  printf("Testudo\n");
  novo->info=malloc(p->taminfo);
  novo->indice=malloc(sizeof(int));//Se estourar, tentar sizeof(int) * p->num_ele
  if(novo->info == NULL){
    free(novo);
    return 0;
  }

  memcpy(novo->info, info, p->taminfo);
  memcpy(novo->indice, indice, sizeof(int));//Se estourar, tentar sizeof(int) * p->num_ele
  printf("%d\n",*novo->indice );
  novo->proximo = p->cabeca;
  p->cabeca = novo;
  p->num_ele += 1;

  return 1; //  sucesso.

}

int removeDoInicio(Lista *p, void *info, int *indice){
  if(matriz_vazia(*p))
    return  ERRO_MATRIZ_VAZIA;

  memcpy(info, p->cabeca->info, p->taminfo);
  memcpy(indice, p->cabeca->indice, sizeof(int));

  Elemento *aux = p->cabeca;

  p->num_ele -= 1;

  p->cabeca = aux->proximo;

  free(aux->info);
  free(aux->indice);
  free(aux);

  return 1;
}


void mostra_matriz(Lista l, void (*mostra)(void *), int linha, int coluna){
    int i, j;

    if(matriz_vazia(l))
      printf("Matriz vazia!\n");
    else {
      printf("Dados da matriz:\n");
      for (i = 0; i < linha; i++) {
          for ( j = 0; j < coluna ; j++) {
            if (l.cabeca->info == NULL){
              printf(" 0 |");
            }else{
              mostra(l.cabeca->info);
            }
          }
        /*Elemento *p = l.cabeca;
          while (p != NULL) {
              mostra(p->info);
              p = p->proximo;
          }*/
        }
    }
}

int insereNoFim(Lista *l, void *info, int *indice){
  if(matriz_vazia(*l))
    return insereNoInicio(l, info, indice);
  Elemento *p = l->cabeca;
  while(p->proximo!=NULL){
    p=p->proximo;
  }
  Elemento *novo = aloca_ele(indice, info, l->taminfo);

  if(novo == NULL)
    return 0;
  p->proximo = novo;
  novo->proximo = NULL;

  l->num_ele += 1;

  return 1;

}

Elemento *aloca_ele(int *indice, void *info, int t){
  Elemento *p = malloc(sizeof(Elemento));
  if(p==NULL)
    return NULL;
  p->info = malloc(t);
  p->indice = malloc(sizeof(int));
  if(p->info ==   NULL){
    free(p);
    return NULL;
  }
  if(p->indice ==   NULL){
    free(p);
    return NULL;
  }
  memcpy(p->info, info, t);
  memcpy(p->indice, indice, sizeof(int));
  return p;
}

int removeDoFim(Lista *l, void *info, int *indice){
  if(matriz_vazia(*l))
    return  ERRO_MATRIZ_VAZIA;

  if(l->cabeca->proximo==NULL)
    return removeDoInicio(l, info, indice);

  Elemento *p = l->cabeca;

  while(p->proximo-> proximo!= NULL){
      p=p->proximo;
  }
  Elemento *aux = p->proximo;

  memcpy(info, aux->info,l->taminfo);
  memcpy(indice, aux->info,sizeof(int));

    l->num_ele -= 1;

  free(aux -> info);
  free(aux);

  p->proximo = NULL;

  return 1 ;
}

int contaElementos(Lista *l){
    int cont = 0;
    if(matriz_vazia(*l))
        return  ERRO_MATRIZ_VAZIA;

    while(l->cabeca != NULL){
        cont += 1;
    }

    printf("%d", cont);

    return 0;
}

int insereNaPosicao(Lista * l, void *info,int pos, int *indice){
  if (pos < 0 || pos > l->num_ele)
    return ERRO_POSICAO_INVALIDA;

  if (pos == 0) {
    return insereNoInicio(l, info, indice);
  }
  if (pos == l->num_ele) {
    return insereNoFim(l, info, indice);
  }
  Elemento *p = l->cabeca;
  int cont = 0;

  while (cont < pos - 1) {
    p = p->proximo;
    cont ++;
  }
  Elemento *novo = aloca_ele(indice, info, l->taminfo);
  if(novo == NULL)
    return 0;

  novo -> proximo = p->proximo;

  p->proximo = novo;

  l->num_ele += 1;

  return 1;
}

int removeDaPosicao(Lista *l, void *info, int pos, int *indice){
    if(matriz_vazia(*l))
        return ERRO_MATRIZ_VAZIA;

    if (pos < 0 || pos > l->num_ele)
      return ERRO_POSICAO_INVALIDA;

    if (pos == 0) {
      return removeDoInicio(l, info, indice);
    }
    if (pos == l->num_ele) {
      return removeDoFim(l, info, indice);
    }

    Elemento *p = l->cabeca;
    int cont = 0;

    while(cont< pos-1){
        p=p->proximo;
        cont++;
    }
    Elemento *aux = p->proximo;

    p->proximo = aux->proximo;

    memcpy(info, aux ->info, l->taminfo);
    memcpy(indice, aux ->indice, sizeof(int));

    free(aux->info);
    free(aux->indice);
    free(aux);

    l->num_ele--;

    return 1;
}

int modificaNaPosicao(Lista *l, void *info, int pos, int *indice){
    if(matriz_vazia(*l))
        return ERRO_MATRIZ_VAZIA;

    if (pos < 0 || pos > l->num_ele)
      return ERRO_POSICAO_INVALIDA;

    Elemento *p = l->cabeca;
    int cont = 0;

    while(cont< pos-1){
        p=p->proximo;
        cont++;
    }
    memcpy(p->info, info, l->taminfo);
    memcpy(p->indice, indice, sizeof(int));
    return 1;
}
int leNaPosiscao(Lista *l, void *info, int pos, int *indice){
  if(matriz_vazia(*l))
      return ERRO_MATRIZ_VAZIA;

  if (pos < 0 || pos > l->num_ele)
    return ERRO_POSICAO_INVALIDA;

  Elemento *p = l->cabeca;
  int cont = 0;

  while(cont< pos-1){
      p=p->proximo;
      cont++;
  }
  memcpy(info, p->info, l-> taminfo);
    memcpy(indice, p->indice, sizeof(int));

  return 1;
}

int insereEmOrdem(Lista *l, void *info, int (*compara)(void *, void *), int* indice){
  int cont = 0;
  Elemento *p =l->cabeca;
  while(p!=NULL && compara(info, p->info) > 0){
    cont ++;
    p = p->proximo;
  }
  return insereNaPosicao(l, info, cont, indice);
}

//cria matrizEsparca
Lista *matriz(Lista m, int l, int c){
  int i, j, x;
  //cria lista 1
  Lista componentes;
  for (i = 0; i < l; i++) {
      inicializa_lista(&componentes, sizeof(int));
      for ( j = 0; j < c ; j++) {
          printf("valor para a posiçao [%d,%d] =", i, j );
          scanf("%d", &x);
          if (x != 0) {
              insereNoFim(&componentes, &x, &j);
          }
      }
      insereNoFim(&m, &componentes, &i);
  }
}
