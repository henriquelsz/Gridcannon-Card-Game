/*
 * mesa.c
 *
 *  Created on: 5 de nov de 2019
 *      Author: Henrique Souza
 * 		Github: henriquelsz
 */

#include <stdio.h>
#include <stdlib.h>
#include"baralho.h"


typedef struct elementoMesa
{
	tipoCarta elemento[20];


}tipoElementoMesa;

typedef struct mesa
{
	tipoElementoMesa mesa[7][7];


}tipoMesa;

tipoMesa cartasMesa(tipoMesa mesa, tipoBaralho baralho)
{
	int i, j, k, qtdReal;
	i = 1, j = 1, k = 0, qtdReal = 0;
	while (i <= 5) {
		while (j <= 5) {
			if (i == 1 || j == 1 || i == 5 || j == 5) {
				if((i==1 && j==1)||(i==1 && j==5)||(i==5 && j==1)||(i==5 && j==5)){
					mesa.mesa[i][j].elemento[0].valor = 0;
					mesa.mesa[i][j].elemento[0].naipe = -1;
					mesa.mesa[i][j].elemento[0].naipeC = 'X';
					//Setar o valor 0 para os elemento[1] para poder receberem a armadura
					mesa.mesa[i][j].elemento[10].valor = 0;
					j++;
				}
				else{
				mesa.mesa[i][j].elemento[0].valor = 0;
				mesa.mesa[i][j].elemento[0].naipe = -1;
				mesa.mesa[i][j].elemento[0].naipeC = '@';
				//Setar o valor 0 para os elemento[1] para poder receberem a armadura
				mesa.mesa[i][j].elemento[10].valor = 0;
				j++;
				}
			}
			else if (i == 3 && j == 3) {
				mesa.mesa[i][j].elemento[0].valor = 0;
				mesa.mesa[i][j].elemento[0].naipe = -1;
				mesa.mesa[i][j].elemento[0].naipeC = '@';
				j++;
			}
			else {
				if (baralho.cartas[k].valor == 11 || baralho.cartas[k].valor == 12 || baralho.cartas[k].valor == 13) {
					mesa.mesa[1][1].elemento[qtdReal+1].valor = baralho.cartas[k].valor;
					mesa.mesa[1][1].elemento[qtdReal+1].naipe = baralho.cartas[k].naipe;
					mesa.mesa[1][1].elemento[qtdReal+1].naipeC = baralho.cartas[k].naipeC;
					qtdReal++;
					mesa.mesa[2][1].elemento[1].valor = qtdReal; //Variável que retorna quantidade de reais que apareceu no baralho
					k++;
				}
				else {
					mesa.mesa[i][j].elemento[0].valor = baralho.cartas[k].valor;
					mesa.mesa[i][j].elemento[0].naipe = baralho.cartas[k].naipe;
					mesa.mesa[i][j].elemento[0].naipeC = baralho.cartas[k].naipeC;
					k++;
					j++;
				}
			}
		}
		i++;
		j = 1;
	}
	mesa.mesa[5][1].elemento[1].valor = k; //Variável que indica em qual carta parou no baralho
	return(mesa);
}
