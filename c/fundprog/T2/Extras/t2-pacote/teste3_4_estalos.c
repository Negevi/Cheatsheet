/*============================================================================*/
/* Exemplo: adiciona e remove ru�do. */

#include <stdlib.h>
#include "wavfile.c"

#include "trabalho2.h"

/*============================================================================*/

#define INPUT_FILE "data/sonic1.wav"
#define OUTPUT_FILE1 "data/teste3_estalos_meu.wav"
#define OUTPUT_FILE2 "data/teste4_removeEstalos_meu.wav"

/*============================================================================*/

int main ()
{
	WavHeader header; /* Cabe�alho para as informa��es sobre o arquivo. */
	double* data_l; /* Dados do canal esquerdo. Alocado na readWavFile. */
	double* data_r; /* Dados do canal direito. Alocado na readWavFile, se necess�rio. */
    int n_amostras; /* N�mero de amostras nos buffers. */

    /* L� um arquivo. */
    n_amostras = readWavFile (INPUT_FILE, &header, &data_l, &data_r);
    if (!n_amostras)
    {
        printf ("Erro lendo %s.\n", INPUT_FILE);
        return (1);
    }

    /* Adiciona ru�do (deixando o per�odo diferente na esquerda e na direita para ficar bem percept�vel). */
    estalos (data_l, n_amostras, 44100 / 20, -1);
    estalos (data_r, n_amostras, 44100 / 2, 1);

    if (!writeWavFile (OUTPUT_FILE1, &header, data_l, data_r))
    {
        printf ("Erro salvando %s.\n", OUTPUT_FILE1);
        return (1);
    }

    /* Remove ru�do. */ 
    removeEstalos (data_l, n_amostras);
    removeEstalos (data_r, n_amostras);

    if (!writeWavFile (OUTPUT_FILE2, &header, data_l, data_r))
    {
        printf ("Erro salvando %s.\n", OUTPUT_FILE2);
        return (1);
    }

    // Desaloca os vetores. O direito s� vai ter sido alocado se o arquivo for est�reo.
	free (data_l);
	if (data_r)
        free (data_r);

	return (0);
}
void estalos(double* dados, int n_amostras, int intervalo_max, double valor1) {

    int amostra_intervalo_rand, amostras_percorridas = n_amostras; // variavel indicadora do "tempo" percorrido do .wav

    amostra_intervalo_rand = rand() % intervalo_max; // encontra uma certa amostra entre [0, intervalo_max - 1]
    dados[amostra_intervalo_rand] = valor1;
    valor1 *= -1; // faz a troca de valor1
    amostras_percorridas -= intervalo_max;

    /* a parte acima roda 1 vez para suprir a necessidade solicitada. 
    Nao entendi muito bem, talvez tenha algo a ver com a pos. 0 ser especial.
    Lembro de algo assim sendo comentado em aula, mas esqueci. */

    while(amostras_percorridas > 0) {
        amostra_intervalo_rand = rand() % intervalo_max + 1; // encontra uma certa amostra entre [1, intervalo_max]
        dados[(n_amostras - amostras_percorridas) + amostra_intervalo_rand] = valor1; // (n_amostras - amostras_percorridas) + amostra == amostra presente + valor rand.
        valor1 *= -1; // faz a troca de valor1

        amostras_percorridas -= intervalo_max; // conta o numero de intervalos percorridos
    }
}

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
    free(vec_original); // claro que esqueci disso
}

/*============================================================================*/
