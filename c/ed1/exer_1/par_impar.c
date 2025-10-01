#include "queue.h"

int main () {
  int i, n = 10;	
  /*Use somente as operações definidas em queue.h*/
  /*Não use para resolver esse exercício o operador -> aqui!*/
  Queue* q = create(n);

  while(n > 0) {
    printf("%d\n", n);
  }

  return 0;
}

