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

