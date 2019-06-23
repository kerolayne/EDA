#define ERRO_MATRIZ_VAZIA -1
#define ERRO_POSICAO_INVALIDA -2


typedef struct {
  int linha;
  int coluna;
  int valor;

}EntradaMatriz;

typedef struct  {
  Lista m;
  int nLinha;
  int nColuna;

}MatrizEsparsa;

int inicializa_matriz(Lista m, int l, int c);

void mostra_matriz(MatrizEsparca mat);

void lePosicaoMatriz(MatrizEsparca &matriz, int linha, int coluna);

int insereNaPosicaoMatriz(MatrizEsparca &matriz, int linha, int coluna);
