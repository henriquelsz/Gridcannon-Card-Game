/*
 * baralho.h
 *
 *  Created on: 5 de nov de 2019
 *      Author: usuarios
 */

#ifndef BARALHO_H_
#define BARALHO_H_

typedef enum naipes
{
	Paus,
	Ouros,
	Espadas,
	Copas,
	Joker
}tipoNaipe;

typedef struct Carta
{

	int valor;
	tipoNaipe naipe;
	char naipeC;
}tipoCarta;

typedef struct Baralho
{
	tipoCarta cartas[55];

}tipoBaralho;

tipoBaralho inicializacaoBaralho(tipoBaralho baralho);
tipoBaralho ramdomizacaoBaralho(tipoBaralho random);
tipoBaralho converteIntChar(tipoBaralho baralho);

#endif /* BARALHO_H_ */
