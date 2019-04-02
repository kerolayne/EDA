#define ERRO_PILHA_CHEIA -1
#define ERRO_PILHA_VAZIA -2

typedef struct{
  void **dados;
  int topo, capacidade;
  ,int tamInfo;
}PilhaGenerica;

vvoid inicializa_pilha(PilhaGenerica *p, int t, int c);
int pilha_vazia(PilhaGenerica p);
int emplilha(PilhaGenerica *p, int info);
int desempilha(PilhaGenerica  *p, int info);
int pilha_cheia(PilhaGenerica  p);
void desaloca(PilhaGenerica  *p);
void mostra_pilha(PilhaGenerica  p);
