/*============================================================================*/
/* DETERMINA OS RET�NGULOS ENVOLVENTES DE BLOBS EM UMA M�SCARA BIN�RIA        */
/*----------------------------------------------------------------------------*/
/* Autor: Bogdan T. Nassu                                                     */
/*============================================================================*/

#ifndef __TRABALHO3_H
#define __TRABALHO3_H

/*============================================================================*/

#include "imagem.h"

/*============================================================================*/
/* Um tipo simples, usado para representar uma coordenada. */
typedef struct
{
    int x;
    int y;
} Coordenada;

/* Um tipo simples, usado para representar um ret�ngulo envolvente. */
typedef struct
{
    Coordenada tl; // top-left.
    Coordenada br; // bottom-right
} Rect;

/*============================================================================*/
/* Fun��o central do trabalho. */

Rect* encontraFuros (Imagem1C* mask, int* n_furos);

/*============================================================================*/
#endif /* __TRABALHO3_H */
