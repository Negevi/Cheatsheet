/*=========================================================================================================*/
/* C�digo desenvolvido por: Chan Hong Lik, Gustavo Olsson Felchner e Nicolas*/
#include "trabalho3.h"
#include <stdlib.h>
#include <stdio.h> // REMOVER ISSO

/*=========================================================================================================*/
/*Prot�tipos das fun��es utilizadas:*/
Rect encontraRect(unsigned char** dados, int y, int x);
int encontraLeft(unsigned char** dados, int y, int x);
int encontraRight(unsigned char** dados, int y, int x);
int encontraBottom(unsigned char** dados, int y, int x);
void preencherFuro(unsigned char** dados, int y, int x);
unsigned char** copiaDados(Imagem1C* mask);
void destroiCopia(unsigned char** dados, int altura);
/*=========================================================================================================*/
Rect* encontraFuros(Imagem1C* mask, int* n_furos) {
    unsigned char** dados_copia;
    dados_copia = copiaDados(mask); // Copia de mask para ser utilizada como referencia

    int furos = 0;
    Rect* retangulos;

    for(int y = 0; y < mask->altura; y++) {
        for(int x = 0; x < mask->largura; x++) {
            if(dados_copia[y][x] > 127) { //se for furo
                furos++;
                if(furos == 1)
                    retangulos = (Rect*) malloc (sizeof(Rect));
                else
                    retangulos = (Rect*) realloc(retangulos, sizeof(Rect) * furos); //revisar esse realloc!
                retangulos[furos-1] = encontraRect(dados_copia, y, x);
                preencherFuro(dados_copia, y, x);

            }
        }
    }
    *n_furos = furos;
    destroiCopia(dados_copia, mask->altura);
    return retangulos;
}

Rect encontraRect(unsigned char** dados, int y, int x) {
    Rect retangulo;
    Coordenada tl, br;
    tl.y = y; //y do ponto j� � o y m�ximo
    tl.x = encontraLeft(dados, y, x);
    br.y = encontraBottom(dados, y, x);
    br.x = encontraRight(dados, y, x);
    retangulo.tl = tl;
    retangulo.br = br;


    return retangulo;
}

int encontraLeft(unsigned char** dados, int y, int x) {
    int achou = 0;
    while(!achou) {
        if(dados[y+1][x] > 127)//verificando se � furo
            y++;
        else if(dados[y][x-1] > 127)
            x--;
        else
            achou = 1;
    }
    return x;
}

int encontraRight(unsigned char** dados, int y, int x) {
    int achou = 0;
    while(dados[y][x+1] > 127)
        x++;
    while(!achou) {
        if(dados[y+1][x] > 127)//verificando se � furo
            y++;
        else if(dados[y][x+1] > 127)
            x++;
        else
            achou = 1;
    }
    return x;
}

int encontraBottom(unsigned char** dados, int y, int x) {
    int concluiu = 0; //para garantir que � o bottom, tem que procurar pelos 2 lados
    while(dados[y+1][x] > 127)
        y++;
    while(concluiu!=1) {
        if(dados[y][x+1] > 127)//verificando se � furo
            x++;
        else if(dados[y][x+1] > 127)
            x++;
        else
            concluiu++;
    }
    while(concluiu!=2) {
        if(dados[y+1][x] > 127)//verificando se � furo
            y++;
        else if(dados[y][x+1] > 127)
            x++;
        else
            concluiu++;
    }
    return y;
}

void preencherFuro(unsigned char** dados, int y, int x) {
    if(dados[y][x] > 127){ //verificando se � furo
        dados[y][x] = 0;
        preencherFuro(dados, y+1, x);
        preencherFuro(dados, y, x+1);
        preencherFuro(dados, y, x-1);
    }
}

unsigned char** copiaDados(Imagem1C* mask) {
    unsigned char** copia = malloc(sizeof(unsigned char*) * mask->altura);
        for(int i = 0; i < mask->altura; i++) {
            copia[i] = malloc(sizeof(unsigned char) * mask->largura);
            for(int j = 0; j < mask->largura; j++) {
                copia[i][j] = mask->dados[i][j];
            }
        }
    return copia;
}

void destroiCopia(unsigned char** dados, int altura) {
    for(int i = 0; i < altura; i++) {
        free(dados[i]);
    }
    free(dados);
}