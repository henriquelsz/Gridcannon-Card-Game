/*
 * baralho.c
 *
 *  Created on: 5 de nov de 2019
 *      Author: Henrique Souza
 * 		Github: henriquelsz
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


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


tipoBaralho inicializacaoBaralho(tipoBaralho baralho) {

	int k;
	for (k = 0; k < 54; k++) {
		if (k <= 12) {
			baralho.cartas[k].valor = k + 1;
			baralho.cartas[k].naipe = 0;
		}
		if (k <= 25 && k > 12) {
			baralho.cartas[k].valor = (k + 1) - 13;
			baralho.cartas[k].naipe = 1;
		}
		if (k <= 38 && k > 25) {
			baralho.cartas[k].valor = (k + 1) - 26;
			baralho.cartas[k].naipe = 2;
		}
		if (k <= 51 && k > 38) {
			baralho.cartas[k].valor = (k + 1) - 39;
			baralho.cartas[k].naipe = 3;
		}
		if (k < 54 && k>51) {
			baralho.cartas[k].valor = 0;
			baralho.cartas[k].naipe = 4;
		}
	}
	return(baralho);
}

tipoBaralho ramdomizacaoBaralho(tipoBaralho random) {

	srand(time(NULL));
	int i, j, h;

	for (i = 0; i < 2001; i++)
	{
		j = rand() % 54;

		random.cartas[54].valor = random.cartas[j].valor;
		random.cartas[54].naipe = random.cartas[j].naipe;


		h = rand() % 54;



		random.cartas[j].valor = random.cartas[h].valor;
		random.cartas[j].naipe = random.cartas[h].naipe;


		random.cartas[h].valor = random.cartas[54].valor;
		random.cartas[h].naipe = random.cartas[54].naipe;





	}
	return(random);
}

tipoBaralho converteIntChar(tipoBaralho baralho) {
	int k;
	for (k = 0; k < 54; k++) {
		if (baralho.cartas[k].naipe == 0) {
			baralho.cartas[k].naipeC = 'P';
		}
		else if (baralho.cartas[k].naipe == 1) {
			baralho.cartas[k].naipeC = 'O';
		}
		else if (baralho.cartas[k].naipe == 2 ) {
			baralho.cartas[k].naipeC = 'E';
		}
		else if (baralho.cartas[k].naipe == 3) {
			baralho.cartas[k].naipeC = 'C';
		}
		else if (baralho.cartas[k].naipe == 4) {
			baralho.cartas[k].naipeC = 'J';
		}
	}
	return(baralho);
}
