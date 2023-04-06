/*
 * Controller.h
 *
 *  Created on: 6 de nov de 2019
 *      Author: usuarios
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



tipoMesa posicionarReais(tipoMesa MESA, tipoBaralho Baralho);
tipoCarta comprarCarta(tipoMesa MESA, tipoBaralho Baralho, tipoCarta cartaNova);
tipoMesa armadura(tipoMesa MESA, int linha, int coluna, tipoCarta carta);
tipoMesa reset(tipoMesa MESA, tipoBaralho Baralho, int linha, int coluna, tipoCarta carta);
tipoMesa gatilho(tipoMesa MESA, int linha, int coluna);
tipoMesa posicionarCartaNova(tipoMesa MESA, tipoBaralho Baralho, tipoCarta carta);


#endif /* CONTROLLER_H_ */
