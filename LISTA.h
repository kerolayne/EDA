#define ERRO_LISTA_VAZIA -1

typedef struct ele{
    void *info;
    struct ele *proximo; 
    
}Elemento; 

typedef struct{
  Elemento *cabeca; 
  int taminfo;
}Lista; 
