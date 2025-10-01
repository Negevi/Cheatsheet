#include "stack.h"

int parser (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;
  int counter1 = 0;
  int counter2 = 0;
  char var;

  while (c[i] != '\0') {
    var = c[i];

    if(var == '(')
      counter1++;
    if(var == '[')
      counter2++;
    if(var == ')')
      counter1--;
    if(var == ']')
      counter2--;

    if(counter1 < 0 || counter2 < 0)
      break;

    i++;
  }

  if(counter1 == 0 && counter2 == 0)
    return 1;
  return 0;
}

int main () {
  //char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  char *c = "( ) [ ]";
  //char *c = "( [ ]";
  //char *c = ") (";
  if (parser(c)) 
    printf("true  (bem formada)\n");
  else  
    printf("false (mal formada)\n");
  return 0;
}
