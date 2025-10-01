#include <stdio.h>

float calculaValorDevido (float peso, float custo_fixo, float preco_kg, float largura_faixa, float desconto_faixa, float desconto_max) {   
    float preco_final = custo_fixo; // ja adicionando custo_fixo ao preco final
    int i, i_max = desconto_max / desconto_faixa; // iteracoes maximas antes de atingir desconto_max

    if(largura_faixa + desconto_faixa + desconto_max == 0) {
        preco_final = custo_fixo + (peso * preco_kg * 0.001);
        printf("%.2f", preco_final); // caso Gisele queira utilizar a outra forma de calcular
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

void main() {
    calculaValorDevido(500, 7, 16, 0, 0, 0);
}