/*
 * Viwer.c
 *
 *  Created on: 6 de nov de 2019
 *      Author: usuarios
 */

#include<stdio.h>
#include<stdlib.h>
#include"baralho.h"
#include"mesa.h"

void printMesa(tipoMesa MESA, tipoBaralho Baralho){
	int x, y;
	for (x = 1; x <= 5; x++) {
		for (y = 1; y <= 5; y++) {
			if(x==1||x==5||y==1||y==5){
				if(MESA.mesa[x][y].elemento[10].valor != 0){
					printf("%d%c+%d\t",MESA.mesa[x][y].elemento[0].valor, MESA.mesa[x][y].elemento[0].naipeC, MESA.mesa[x][y].elemento[10].valor);
				}
				else{
					printf("%d%c\t", MESA.mesa[x][y].elemento[0].valor, MESA.mesa[x][y].elemento[0].naipeC);
				}
			}
			else{
				printf("%d%c\t", MESA.mesa[x][y].elemento[0].valor, MESA.mesa[x][y].elemento[0].naipeC);
			}
		}
		printf("\n");
	}
}


