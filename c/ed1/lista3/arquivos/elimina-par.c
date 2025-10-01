#include "stack.h"

int main () {
  int tam = 6;
  Stack *s = create (tam);
  srand(time(NULL));
  int i;
  for (i = 0; i < tam; i++) {
    push (s, rand()%10);
  }
  print (s);

  for(i = 0; i < tam; i++) {
    if(get_peek(s) % 2 == 0 || get_peek(s) == 0) {
      pop(s);
    } else {
      continue;
    }
  }

  print (s);

  destroy (s);
}
