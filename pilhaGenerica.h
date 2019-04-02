#define ERRO_PILHA_CHEIA -1
#define ERRO_PILHA_VAZIA -2

typedef struct{
  void **dados;
  int topo, capacidade;
  int tamInfo;
}PilhaGenerica;

void inicializa_pilha(PilhaGenerica *p, int t, int c);
int pilha_vazia(PilhaGenerica p);
int empilha(PilhaGenerica *p, void *info);
int desempilha(PilhaGenerica *p, void *info );
int pilha_cheia(PilhaGenerica  p);
void desaloca(PilhaGenerica  *p);
void mostra_pilha(PilhaGenerica p, void(*mostra)(void*));
