/*============================================================================*/
/* ICSF13 - 2025-1 - TRABALHO 2                                               */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu                                                            */
/* Leyza E. B. Dorini                                                         */
/* Daniel F. Pigatto                                                          */
/*============================================================================*/
/** Fun��es pedidas para o 2o trabalho da disciplina Fundamentos de Programa��o
 * 1, 1o semestre de 2025, profs. Bogdan T. Nassu, Leyza E. B. Dorini e Daniel
 * F. Pigatto, Universidade Tecnol�gica Federal do Paran�. */
/*============================================================================*/

#ifndef __TRABALHO2_H
#define __TRABALHO2_H

/*============================================================================*/

#define TRAB_PI 3.1415926536

/*============================================================================*/

void mudaGanho (double* dados, int n_amostras, double ganho);
void simulaSubAmostragem (double* dados, int n_amostras, int n_constantes);
void estalos (double* dados, int n_amostras, int intervalo_max, double valor1);
void removeEstalos (double* dados, int n_amostras);
void geraOndaQuadrada (double* dados, int n_amostras, int taxa, double freq);
void geraSenoide (double* dados, int n_amostras, int taxa, double freq, double fase);

/*============================================================================*/
#endif // __TRABALHO2_H
