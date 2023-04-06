/*
 * mesa.h
 *
 *  Created on: 5 de nov de 2019
 *      Author: usuarios
 */

#ifndef MESA_H_
#define MESA_H_

#include<stdio.h>
#include<stdlib.h>
#include"baralho.h"


typedef struct elementoMesa
{
	tipoCarta elemento[20];


}tipoElementoMesa;

typedef struct mesa
{
	tipoElementoMesa mesa[7][7];


}tipoMesa;

tipoMesa cartasMesa(tipoMesa mesa, tipoBaralho baralho);


#endif /* MESA_H_ */
