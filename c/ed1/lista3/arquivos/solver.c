#include "stack.h"

int compute_polish_expression (char *c) {
  Stack *s = create(strlen(c));
  /*Terminar*/
  /*....*/
  //return sol;
}

int main () {
  char *c = "9 0 1 + 2 3 * * +";
  printf("Resultado: %d\n", compute_polish_expression(c));
  return 0;
}
