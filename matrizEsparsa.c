#include "matrizEsparsa.h"
#include "LISTA.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void inicializa_matriz(MatrizEsparsa *matriz, int linha, int coluna){

    matriz->nlinha = linha ;
    matriz->ncoluna = coluna;
    inicializa_lista(&matriz->m, sizeof(Lista));
    int i;
    for (i = 0; i < linha; i++) {
      Lista l;
      inicializa_lista(&l, sizeof(EntradaMatriz));
      insereNoFim(&matriz->m, &l);
    }
}
//insere na posição
int insereNaPosicaoMatriz(MatrizEsparsa matriz, int linha, int coluna, int valor){
    EntradaMatriz e;
    e->linha = linha;
    e->coluna = coluna;
    e->valor = valor;
    Lista *lista = matriz->m;
    Elemento *elemento = lista->prox;
    int i = 0;
    for(i; i < linha - 1; elemento = elemento->prox);
    Lista *listaColuna = elemento->info;
    Elemento *elementoColuna = listaColuna->proximo;
    if(elementoColuna == NULL){ //Insere aqui)
        inserNoFim(listaColuna, e);
    }
    Elemento *auxiliar;
    else{
        while(elementoColuna != NULL && elementoColuna->coluna > coluna){
            auxiliar = elementoColuna;
            elementoColuna = elementoColuna->proxima;
        }
        if(elementoColuna == NULL){
            inserNoFim(listaColuna, e);
        }
        else{
            Elemento *novo = malloc(sizeof(Elemento));
            novo->coluna = coluna;
            novo->proximo = elementoColuna;
            auxiliar->proximo = novo;
        }
    }
}

//le na posiçao
//void lePosicaoMatriz(MatrizEsparsa &matriz, int linha, int coluna){

//}

//remove na posição
/*
int removeNaPosicaoMatriz(){

    return 0;
}
//
/*
int matrix(Lista m, int l, int c){
  int i, j, x;
  Lista s;
  for (i = 0; i < l; i++) {
      inicializa_lista(&s);
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
*/
void mostra_matriz(MatrizEsparsa mat){
    Lista l;
    int i, j, k, w;

    for ( i = 0; i < mat.nlinha ; i++) {
      leNaPosiscao(&mat.m, &l, i);
      j = 0; k = 0;
      EntradaMatriz e;
      if (!lista_vazia(l)) {
          while (leNaPosiscao(&l, &e, k)!=ERRO_POSICAO_INVALIDA) {
            for (size_t w = 0; w < e.coluna; w++) {
              printf("0  ");
            }
            printf("%d\n", e.valor);
            k++;
            j = e.coluna + 1;
          }
      }
      for (w = j; w < mat.ncoluna; w++) {
        printf("0  ");
      }
      printf("\n");
    }
}
