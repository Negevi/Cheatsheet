// Trabalho 2. Feito por Nicolas Lisboa Lemke (RA-2751542) e Aliny Ventura (RA-2783991), Eng. Comp

#include <math.h>
#include <stdlib.h>
#include "trabalho2.h"

// Função 1: Modifica o ganho (volume) do sinal
void mudaGanho(double* dados, int n_amostras, double ganho) {
    // Percorre todas as amostras
    for (int i = 0; i < n_amostras; i++) {
        dados[i] = dados[i] * ganho;  // Aplica o ganho
    }
}
// Função 2: Simula uma subamostragem no sinal
void simulaSubAmostragem(double* dados, int n_amostras, int n_constantes) {
    // Percorre o vetor em blocos de n_constantes
    for (int i = 0; i < n_amostras; i += n_constantes) {
        double valor = dados[i];  // Salva o valor da primeira amostra do bloco

        // Define os limites para o bloco (sem ultrapassar o vetor)
        int limite = i + n_constantes;
        if (limite > n_amostras) {
            limite = n_amostras;
        }

        // Substitui todas as amostras do bloco pelo valor inicial
        for (int j = i; j < limite; j++) {
            dados[j] = valor;
        }
    }
}
// Func. 3: Adiciona estalos 
void estalos(double* dados, int n_amostras, int intervalo_max, double valor1) {

    int amostra_intervalo_rand, amostras_percorridas = n_amostras; // variavel indicadoraa do "tempo" percorrido do .wav

    amostra_intervalo_rand = rand() % intervalo_max; // encontra uma certa amostra entre [0, intervalo_max - 1]
    dados[amostra_intervalo_rand] = valor1;
    valor1 *= -1; // faz a troca de valor1
    amostras_percorridas -= intervalo_max;

    /* a parte acima roda 1 vez para suprir a necessidade solicitada. 
    Nao entendi muito bem, talvez tenha algo a ver com a pos. 0 ser especial.
    Lembro que algo assim sendo comentado em aula, mas esqueci. */

    while(amostras_percorridas > 0) {
        amostra_intervalo_rand = rand() % intervalo_max + 1; // encontra uma certa amostra entre [1, intervalo_max]
        dados[(n_amostras - amostras_percorridas) + amostra_intervalo_rand] = valor1; // (n_amostras - amostras_percorridas) + amostra == amostra presente + valor rand.
        valor1 *= -1; // faz a troca de valor1

        amostras_percorridas -= intervalo_max; // conta o numero de intervalos percorridos
    }
    // Agora q entendi o nome sonic 1
}
// Func. 4 Remove estalos
void removeEstalos(double* dados, int n_amostras) {
    int i;
    double left, mid, right;
    double* vec_original = malloc(n_amostras * sizeof(double)); 
    /* Tentei com todas as forcas nao criar um novo vetor, mas o codigo ficou feio d+ */
    for(i = 0; i < n_amostras; i++)
        vec_original[i] = dados[i]; // copia os vetores
    
    for(i = 1; i < (n_amostras - 1); i++) { // comeca no 1 e termina em n_amostras - 1, como especificado no exer.

        left = vec_original[i - 1];
        mid = vec_original[i];
        right = vec_original[i + 1];

        // filtro de mediana.

        if((left >= mid) && (left >= right)) {
            if(mid > right) {
                dados[i] = mid;
            } else {
                dados[i] = right;
            }
        } else if((mid >= left) && (mid >= right)) {
            if(left > right) {
                dados[i] = left;
            } else {
                dados[i] = right;
            }
        } else {
            if(mid > left) {
                dados[i] = mid;
            } else {
                dados[i] = left;
            }
        }
    }
    free(vec_original);
}
// Func 5. Gera sinal quadrado
void geraOndaQuadrada(double* dados, int n_amostras, int taxa, double freq) {
	int i, high_low = 1, contador_amostras = 0, amostras_por_ciclo = taxa / (int)(freq + 0.5); //aqui, defino 1 ciclo como uma sequencia de alto e outra de baixo.
	double erro = (taxa / freq) - ((int)(taxa / freq)), erro_cumulativo = 0;
	while(contador_amostras < n_amostras) {
		
		for(i = 0; i < (amostras_por_ciclo / 2); i++) { // itera enquanto I nao completar um semi-ciclo
			dados[i + contador_amostras] = high_low;
		}
		high_low *= -1; // troca o valor do double
		erro_cumulativo += erro;
		if(erro_cumulativo > 1) {
			contador_amostras += (1 + i);
			erro_cumulativo -= 1;
		}
		else
			contador_amostras += i; // conta quantas amostras ja foram completadas
	}
}
// Func 6. Gera sinal senoide
void geraSenoide(double* dados, int n_amostras, int taxa, double freq, double fase) {
	int i;
	double angulo;
    for (i = 0; i < n_amostras; i++) {
        angulo = 2 * TRAB_PI * freq / taxa * i; // (2PI / (taxa * periodo)) * i
        dados[i] = sin(angulo + fase); // angulo calculado + fase
    }
}