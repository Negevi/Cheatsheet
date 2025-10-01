#include <stdio.h>
int codigoValido (unsigned int n, int tamanho) {
    int i, contador = 0;
    if(tamanho == 1 && n & 0)
        return 1;
    if(tamanho % 2 == 0 || n & 1) // adimito que essa ultima cond. eu peguei do chat gpt ;)
        return 0; // se tamanho for par, a seq. sera invalida

    for(i = 0; i < tamanho; i++) {
        if((n >> (tamanho - i)) & 1) { // se o valor lido (esquerda para a direita) for == 1
            contador -= 1;
        } else {
            contador +=1; // se o valor lido (esquerda para a direita) for == 0
        } 

        if(contador <= 0) { // se o valor for negativo ou zero, a sequencia instantaneamente torna-se valida por 1's sem sequencias validas
            return 0;
        }
    }
    if(contador == 1) // somente retorna se for == 1. Caso seja > 1, significa que algum 0 nao foi pareado.
        return 1;
    return 0;
}
#include <stdio.h>
#include <math.h>
#define N_BITS 7

/* Mostra os últimos bits de um número. */
void mostraBits (unsigned int n, int tamanho)
{
int i;
for (i = 0; i < tamanho; i++)
printf ("%d", 1 & n >> (tamanho-i));
printf ("\n");
}
int main ()
{
unsigned int i;
int contagem = 0;
/* Gera e testa todas as sequências possíveis com N_BITS. */
for (i = 0; i < pow (2, N_BITS); i++)
{
if (codigoValido (i, N_BITS))
{
mostraBits (i, N_BITS);
contagem++;
}
}
printf ("%d sequencias encontradas.\n", contagem);
return (0);
}