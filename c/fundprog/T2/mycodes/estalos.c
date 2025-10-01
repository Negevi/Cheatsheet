#include "wavfile.h"
#include <stdlib.h>

void estalos(double* dados, int n_amostras, int intervalo_max, double valor1) {
    // srand(time(NULL)); nao deixei no codigo por medo de incluir ou nao o <time.h> (windows reclamou por nao incluir, mas o linux nao... vai entender)

    int amostra, amostras_percorridas = n_amostras; // variavel indicadoraa do "tempo" percorrido do .wav

    amostra = rand() % intervalo_max; // encontra uma certa amostra entre [0, intervalo_max - 1]
    dados[amostra] = valor1;
    valor1 *= -1; // faz a troca de valor1

    /* a parte acima roda 1 vez para suprir a necessidade solicitada. 
    Nao entendi muito bem, talvez tenha algo a ver com a pos. 0 ser especial.
    Lembro de algo assim sendo comentado em aula, mas nao estou lembrado */

    while(amostras_percorridas < n_amostras) {

        amostra = rand() % intervalo_max + 1; // encontra uma certa amostra entre [1, intervalo_max]
        dados[amostra] = valor1;
        valor1 *= -1; // faz a troca de valor1

        amostras_percorridas -= intervalo_max; // conta o numero de intervalos percorridos
    }
}