#define ERRO_MATRIZ_VAZIA -1
#define ERRO_POSICAO_INVALIDA -2

typedef struct ele{
    void *info;
    int *indice;
    struct ele *proximo;
}Elemento;

typedef struct{
  Elemento *cabeca;
  int taminfo;
  int num_ele;
}Lista;


void inicializa_lista(Lista *p, int c);

int matriz_vazia(Lista l);

int insereNoInicio(Lista *p, void *info, int *indice);

int removeDoInicio(Lista *p, void *info, int *indice);

void mostra_matriz(Lista l, void (*mostra)(void *), int linha, int coluna);

int insereNoFim(Lista *l, void *info, int *indice);

int removeDoFim(Lista *l, void *info, int *indice);

int contaElementos(Lista *l);

int insereNaPosicao(Lista * l, void *info, int pos, int *indice);

int removeDaPosicao(Lista *l, void *info, int pos, int *indice);

int modificaNaPosicao(Lista *l, void *info, int pos, int *indice);

int leNaPosiscao(Lista *l, void *info, int pos, int *indice);

int insereEmOrdem(Lista *l, void *info, int (*compara)(void *, void *), int *indice);

Lista *matriz(Lista m, int l, int c);
//int desaloca_lista()
