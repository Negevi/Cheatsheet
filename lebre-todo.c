#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void moveTartaruga(int, int *);
void moveLebre(int, int *);
void imprimePosicoesAtuaisSimples(int, int);
void imprimePosicoesAtuais(int ptrTar, int ptrLeb);

int main()
{
    int tartaruga = 0, lebre = 0;

    srand(time(NULL));

    while(tartaruga < 70 && lebre < 70)
    {
        moveTartaruga (rand()%10+1, &tartaruga);
        moveLebre (rand()%10+1, &lebre);

        /*TODO: depois que você executar o programa, comente a chamada
                para a  funcao imprimePosicoesAtuaisSimples() e
                descomente chamada para a funcao imprimePosicoesAtuais()*/
        //imprimePosicoesAtuaisSimples (tartaruga, lebre);
        imprimePosicoesAtuais (tartaruga, lebre);
    }
    if (tartaruga >= lebre)
        printf ("Tartaruga ganhou!!!\n");
    else
        printf ("Lebre Ganhou!!!\n");

    return 0;
}


void moveTartaruga(int valor_sorteado, int *ptrTar)
{
    if(valor_sorteado <= 5)
        *ptrTar += 3;
    else if(valor_sorteado < 8)
        *ptrTar -= 6;
    else
        *ptrTar += 1;

    if(*ptrTar < 0)
        *ptrTar = 0;
    if(*ptrTar > 70)
        *ptrTar = 70;
}

void moveLebre(int valor_sorteado, int *ptrLeb)
{
    if(valor_sorteado <= 4)
        *ptrLeb += 9;
    else if(valor_sorteado == 5)
        *ptrLeb -= 12;
    else if(valor_sorteado <= 8)
        *ptrLeb += 1;
    else if(valor_sorteado <= 10)
        *ptrLeb -= 2;

    if(*ptrLeb < 0)
        *ptrLeb = 0;
    if(*ptrLeb > 70)
        *ptrLeb = 70;
}

void imprimePosicoesAtuaisSimples(int ptrTar, int ptrLeb)
{
    int i;

    for (i = 1; i < 71; i++)
        if (i == ptrTar && i == ptrLeb)
            printf("AI!!!");
        else if (i == ptrLeb)
            printf("L");
        else if (i == ptrTar)
            printf("T");
        else
            printf(" ");

    printf("\n");
}

void imprimePosicoesAtuais(int ptrTar, int ptrLeb)
{
    int i;

    printf("\t\t\tPos. Tartaruga: %2d | Pos. Lebre: %2d\n",ptrTar, ptrLeb);
    printf("*******************************************************************************\n");
    //printf("\n      _\n  .-./*)\n_/___\\/\n  U U"); //desenho tartaruga (base)
    //printf("\n    \\\\ \n     \\\\_ \n  .---(')\no( )_-\\_"); //desenho coelho (base)
    for(i=0; i<ptrTar; i++)
        printf(" ");
    printf("      _\n");
    for(i=0; i<ptrTar; i++)
        printf(" ");
    printf("  .-./*)\n");
    for(i=0; i<ptrTar; i++)
        printf(" ");
    printf("_/___\\/\n");
    for(i=0; i<ptrTar; i++)
        printf(" ");
    printf("  U U");
    printf("\n*******************************************************************************\n\n");

    for(i=0; i<ptrLeb; i++)
        printf(" ");
    printf("    \\\\ \n");
    for(i=0; i<ptrLeb; i++)
        printf(" ");
    printf("     \\\\_ \n");
    for(i=0; i<ptrLeb; i++)
        printf(" ");
    printf("  .---(')\n");
    for(i=0; i<ptrLeb; i++)
        printf(" ");
    printf("o( )_-\\_");
    printf("\n*******************************************************************************\n");
}
