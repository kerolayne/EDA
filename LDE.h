#define ERRO_LISTA_VAZIA -1
#define ERRO_POSICAO_INVALIDA -2

typedef struct ele{
  void *info;
  struct ele *suc, *ant;
}EleDuplo;

typedef struct{
  EleDuplo *cabeca;
  int tamInfo, num_ele;
}LDE;

int insereNoInicio(LDE *p, void *info);

int removeDoInicio(LDE *p, void *info);

int insereNoFim(LDE *l, void *info);
