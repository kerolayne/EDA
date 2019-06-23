#include "LISTA.h"

#define ERRO_MATRIZ_VAZIA -1
#define ERRO_POSICAO_INVALIDA -2


typedef struct {
  int linha;
  int coluna;
  int valor;

}EntradaMatriz;

typedef struct  {
  Lista m;
  int nlinha;
  int ncoluna;

}MatrizEsparsa;

void inicializa_matriz(MatrizEsparsa *matriz, int linha, int coluna);



void mostra_matriz(MatrizEsparsa mat);

//void lePosicaoMatriz(MatrizEsparsa &matriz, int linha, int coluna);

int insereNaPosicaoMatriz(MatrizEsparsa matriz, int linha, int coluna, int valor);
