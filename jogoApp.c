/*
 * Grindcannon game 
 *
 *  Created on: 5 de nov de 2019
 *      Author: Henrique Souza 
 * 		GitHub: henriquelsz
 */

#include<stdio.h>
#include<stdlib.h>
#include"baralho.h"
#include"mesa.h"
#include"Controller.h"
#include"Viwer.h"

void main(){
	tipoBaralho Baralho;
	Baralho = inicializacaoBaralho(Baralho);
	Baralho = ramdomizacaoBaralho(Baralho);
	Baralho = converteIntChar(Baralho);

	tipoMesa MESA;
	MESA = cartasMesa(MESA, Baralho);

	printMesa(MESA,Baralho);
	MESA = posicionarReais(MESA, Baralho);
	printMesa(MESA,Baralho);

	tipoCarta cartaNova;
	printf("\nA carta comprada do baralho: \n");
	while(MESA.mesa[5][5].elemento[1].valor < 0 || MESA.mesa[5][1].elemento[1].valor <= 52 || MESA.mesa[1][5].elemento[1].valor != 6 ){
	cartaNova = comprarCarta(MESA, Baralho, cartaNova);
	MESA = posicionarCartaNova(MESA, Baralho,cartaNova);
	printMesa(MESA, Baralho);
	}
}
