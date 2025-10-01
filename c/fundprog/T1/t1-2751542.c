// feito por Nicolas Lisboa Lemke, RA-2751542, Eng. Comp
#include "trabalho1.h"
float calculaValorDevido (float peso, float custo_fixo, float preco_kg, float largura_faixa, float desconto_faixa, float desconto_max) {   
    float preco_final = custo_fixo; // ja adicionando custo_fixo ao preco final
    int i, i_max = desconto_max / desconto_faixa; // iteracoes maximas antes de atingir desconto_max

    if(largura_faixa + desconto_faixa + desconto_max == 0) {
        preco_final = custo_fixo + (peso * preco_kg * 0.001); // caso Gisele queira utilizar a outra forma de calcular
        return preco_final;
    }
    for(i = 0; i < i_max && peso > largura_faixa; i++) { // enquanto nao atingir o desconto maximo e peso for positivo
        preco_final = preco_final + (largura_faixa * preco_kg * 0.001) * (1.0 - desconto_faixa * i); // preco final = preco da faixa com o desconto aplicado
        peso -= largura_faixa;
    }
    if(i == i_max) 
        preco_final += (peso * preco_kg * 0.001) * (1.0 - desconto_max); // adicionando o restante do valor aplicando desconto_max direto
    else
        preco_final += (peso * preco_kg * 0.001) * (1.0 - desconto_faixa * i); // adicionando o preco da ultima parcela, caso esta seja menor que largura_faixa (valores quebrados)

    return preco_final;
}

unsigned int fourcc(char c1, char c2, char c3, char c4) {
    return (c4 << 24 | c3 << 16 | c2 << 8 | c1); // legal 
}

double raizAproximada (double x, double erro_minimo) {
    double palpite_baixo = 1, palpite_alto = x, aprox = 0;

    if(x <= 1) {
        palpite_baixo = x; // muda os valores de comparação
        palpite_alto = 1;
    }
    
    while(fabs(x - (aprox * aprox)) > erro_minimo) {
        aprox = (palpite_baixo + palpite_alto) / 2;
            if(aprox * aprox > x)
                palpite_alto = aprox; // muda o parametro de cima para a aprox.
            else
                palpite_baixo = aprox; // muda o parametro de baixo para a aprox.
        } // Uma func. bem simples!

    return aprox;
}

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