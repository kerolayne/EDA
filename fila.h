#define ERRO_FILA_CHEIA -1
#define ERRO_FILA_VAZIA -2


typedef struct{
  int *dados;
  int capacidade;
  int inicio, fim, num_ele;
}Fila;

//prototipos das funções
//denição das constantes
