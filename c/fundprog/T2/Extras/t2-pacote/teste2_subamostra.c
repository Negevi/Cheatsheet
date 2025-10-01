/*============================================================================*/
/* Exemplo: sub-amostragem. */

#include <stdlib.h>
#include "wavfile.c"
#include "t2-2751542-2783991.c"
#include "trabalho2.h"

/*============================================================================*/

#define INPUT_FILE "data/sonic1.wav"
#define OUTPUT_FILE "data/teste2_subamostra_meu.wav"

/* Fator de sub-amostragem. */
#define FATOR_L 8
#define FATOR_R 8

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

    simulaSubAmostragem (data_l, n_amostras, FATOR_L);
    simulaSubAmostragem (data_r, n_amostras, FATOR_R);

    /* Salva. */
    if (!writeWavFile (OUTPUT_FILE, &header, data_l, data_r))
    {
        printf ("Erro salvando %s.\n", OUTPUT_FILE);
        return (1);
    }

    /* Desaloca os vetores. O direito s� vai ter sido alocado se o arquivo for est�reo. */
	free (data_l);
	if (data_r)
        free (data_r);

	return (0);
}
