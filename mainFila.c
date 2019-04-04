#include "Fila.h"

int main(int argc, char const *argv[]) {
  Fila f1;

  inicializa_fila(&f1, 5);

  int x = 3;
  inserir(&f1, x);
  remover(&f1, &x)

  printf("removido %d\n", x);
  return 0;
}
