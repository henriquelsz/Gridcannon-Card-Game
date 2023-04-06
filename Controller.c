/*
 * Controller.c
 *
 *  Created on: 6 de nov de 2019
 *      Author: Henrique Souza
 * 		GitHub: henriquelsz
 */

#include<stdio.h>
#include<stdlib.h>
#include"baralho.h"
#include"mesa.h"
#include"Viwer.h"

tipoMesa posicionarReais(tipoMesa MESA, tipoBaralho Baralho){
	MESA.mesa[5][5].elemento[1].valor = 12;
	MESA.mesa[1][5].elemento[1].valor = 0;
	int M;
	int a;

	for(M=0; M<=2; M++){
		for(a = 0; a<= 2; a++){
			MESA.mesa[0][M].elemento[a].valor = 0;
		}
	}



	int linha, coluna, posicaoReal;
		linha = 0, coluna = 0, posicaoReal = MESA.mesa[2][1].elemento[1].valor; //qtd de reais
		while (posicaoReal > 0) {
			printf("\n\nPossui %d cartas reais para distribuir na mesa...\n", posicaoReal);
			printf("\nDiga a linha para posicionar a carta %d%c: ", MESA.mesa[1][1].elemento[posicaoReal].valor, MESA.mesa[1][1].elemento[posicaoReal].naipeC);
			scanf("%d", &linha);
			printf("Diga a coluna para posicionar a carta %d%c: ", MESA.mesa[1][1].elemento[posicaoReal].valor, MESA.mesa[1][1].elemento[posicaoReal].naipeC);
			scanf("%d", &coluna);
			if(MESA.mesa[linha][coluna].elemento[0].naipeC == 'X'||(linha == 3 && coluna == 3)){
				printf("\nPosição inválida! Tente outra posição");
			}
			else if(MESA.mesa[linha][coluna].elemento[0].naipeC != '@'){
				printf("\nJá possuí uma carta neste lugar\n");
				printf("Digite outra posição para posicionar a carta...\n");
			}
			else{
			MESA.mesa[linha][coluna].elemento[0].valor = MESA.mesa[1][1].elemento[posicaoReal].valor;
			MESA.mesa[linha][coluna].elemento[0].naipe = MESA.mesa[1][1].elemento[posicaoReal].naipe;
			MESA.mesa[linha][coluna].elemento[0].naipeC = MESA.mesa[1][1].elemento[posicaoReal].naipeC;
			posicaoReal--;
			}
		}
	return(MESA);
}

tipoMesa gatilho(tipoMesa MESA, int linha, int coluna);

tipoMesa armadura(tipoMesa MESA, int linha, int coluna, tipoCarta carta){

	MESA.mesa[linha][coluna].elemento[10].valor = MESA.mesa[linha][coluna].elemento[10].valor + carta.valor;
	MESA.mesa[5][1].elemento[1].valor++; //k++
	return(MESA);

}

tipoMesa reset(tipoMesa MESA, tipoBaralho Baralho, int linha, int coluna, tipoCarta carta){
	int k, sub;

		if (linha == 2){
			sub = MESA.mesa[0][coluna+2-4].elemento[0].valor;
		}

		if (linha == 3){
			sub = MESA.mesa[0][coluna+2-4].elemento[1].valor;
							}

		if (linha == 4){
			sub = MESA.mesa[0][coluna+2-4].elemento[2].valor;
							}



	for(k = MESA.mesa[5][1].elemento[1].valor;k<=54;k++){
		Baralho.cartas[k-sub].valor = Baralho.cartas[k].valor;
		Baralho.cartas[k-sub].naipe = Baralho.cartas[k].naipe;
		Baralho.cartas[k-sub].naipeC = Baralho.cartas[k].naipeC;
	}
	MESA.mesa[5][1].elemento[1].valor = MESA.mesa[5][1].elemento[1].valor - sub;
	int valor = sub;
	while(sub != -1){
		Baralho.cartas[54-sub].valor = MESA.mesa[linha][coluna].elemento[valor-sub].valor;
		Baralho.cartas[54-sub].naipe = MESA.mesa[linha][coluna].elemento[valor-sub].naipe;
		Baralho.cartas[54-sub].naipeC = MESA.mesa[linha][coluna].elemento[valor-sub].naipeC;
		sub--;
	}
	MESA.mesa[linha][coluna].elemento[0].valor = carta.valor;
	MESA.mesa[linha][coluna].elemento[0].naipe = carta.naipe;
	MESA.mesa[linha][coluna].elemento[0].naipeC = carta.naipeC;
	MESA.mesa[1][5].elemento[1].valor++; //vergonha++
	MESA.mesa[5][1].elemento[1].valor++; //k++

	if (linha == 2){
				MESA.mesa[0][coluna+2-4].elemento[0].valor = 0;
			}

			if (linha == 3){
				MESA.mesa[0][coluna+2-4].elemento[1].valor = 0;
								}

			if (linha == 4){
				MESA.mesa[0][coluna+2-4].elemento[2].valor = 0;
								}


	return(MESA);
}

tipoCarta comprarCarta(tipoMesa MESA, tipoBaralho Baralho, tipoCarta cartaNova){
	int k;

	k = MESA.mesa[5][1].elemento[1].valor; //Qual posição parou o baralho
	cartaNova.valor = Baralho.cartas[k].valor;
	cartaNova.naipe = Baralho.cartas[k].naipe;
	cartaNova.naipeC = Baralho.cartas[k].naipeC;

	return(cartaNova);

}

tipoMesa posicionarCartaNova(tipoMesa MESA, tipoBaralho Baralho, tipoCarta carta){
	int linha, coluna, bool;
	linha = 0, coluna=0, bool=0;

	carta = comprarCarta(MESA, Baralho, carta);

	while(bool==0){
		printf("\nDiga a linha para posicionar a carta %d%c: ", carta.valor, carta.naipeC);
		scanf("%d", &linha);
		printf("Diga a coluna para posicionar a carta %d%c: ", carta.valor, carta.naipeC);
		scanf("%d", &coluna);
		if(carta.valor == 11 || carta.valor == 12 || carta.valor == 13){
			if(MESA.mesa[linha][coluna].elemento[0].naipeC == 'X' || (linha==3 && coluna==3)){
				printf("\nPosição inválida! Tente outra posição");
			}
			else if(MESA.mesa[linha][coluna].elemento[0].naipeC != '@'){
				printf("\nJá possuí uma carta neste lugar\n");
				printf("Digite outra posição para posicionar a carta...\n");
			}
			else{
				if(linha < 1 || linha > 5 || coluna < 1 || coluna > 5){
					printf("\nPosição inválida! Tente outra posição");
				}
				else{
					MESA.mesa[linha][coluna].elemento[0].valor = carta.valor;
					MESA.mesa[linha][coluna].elemento[0].naipe = carta.naipe;
					MESA.mesa[linha][coluna].elemento[0].naipeC = carta.naipeC;
					MESA.mesa[5][1].elemento[1].valor++; //k++
					bool = 1;
				}
			}
		}
		else{
			if((linha==1 || linha==5 || coluna==1 || coluna==5) && (MESA.mesa[linha][coluna].elemento[0].naipeC != 'X' && MESA.mesa[linha][coluna].elemento[0].naipeC != '@')){
				int resposta;
				printf("Deseja adicionar +%d de armadura na carta %d? (SIM = 1, NÃO = 2)\n",carta.valor, MESA.mesa[linha][coluna].elemento[0].valor);
				scanf("%d",&resposta);
				if(resposta == 1){
					MESA = armadura(MESA, linha, coluna, carta);
					bool = 1;
				}
				else if(resposta == 2){
					printf("Digite outra posição!");
				}
				else{
					printf("Resposta inválida");
				}
			}
			else if(linha==1 || linha==5 || coluna==1 || coluna==5 || MESA.mesa[linha][coluna].elemento[0].naipeC == 'X'){
				printf("\nPosição inválida! Tente outra posição");
			}
			else if(MESA.mesa[linha][coluna].elemento[0].naipeC == '@'){
				MESA.mesa[linha][coluna].elemento[0].valor = carta.valor;
				MESA.mesa[linha][coluna].elemento[0].naipe = carta.naipe;
				MESA.mesa[linha][coluna].elemento[0].naipeC = carta.naipeC;
				MESA.mesa[5][1].elemento[1].valor++; //k++
				MESA.mesa[2][1].elemento[1].valor++; //qtd de reais
				bool = 1;
			}
			else{
				if(carta.valor == 1 || carta.naipeC == 'J'){
					if(MESA.mesa[linha][coluna].elemento[0].valor == 11 ||MESA.mesa[linha][coluna].elemento[0].valor == 12 || MESA.mesa[linha][coluna].elemento[0].valor == 13){
							int resposta;
							printf("Deseja adicionar +%d de armadura na carta %d? (SIM = 1, NÃO = 2)\n",carta.valor, MESA.mesa[linha][coluna].elemento[0].valor);
							scanf("%d",&resposta);
							if(resposta == 1){
								MESA = armadura(MESA, linha, coluna, carta);
								bool = 1;
							}
							else if(resposta == 2){
								printf("Digite outra posição!");
							}
							else{
								printf("Resposta inválida");
							}
						}
						else{
							int resposta;
							printf("Deseja fazer o reset da pilha da carta %d%c? (Sim = 1, Não = 2)", MESA.mesa[linha][coluna].elemento[0].valor, MESA.mesa[linha][coluna].elemento[0].naipeC);
							scanf("%d",&resposta);
							if(resposta == 1){
							MESA = reset(MESA, Baralho, linha, coluna, carta);
							MESA = gatilho(MESA, linha, coluna);
							bool = 1;
							}
							else if(resposta == 2){printf("Digite outra posição...");}
							else{printf("Resposta inválida");}
								}
							}
				else if(carta.valor < MESA.mesa[linha][coluna].elemento[0].valor){
					int resposta;
					printf("Deseja fazer o reset forçado da pilha da carta %d%c? (Sim = 1, Não = 2)", MESA.mesa[linha][coluna].elemento[0].valor, MESA.mesa[linha][coluna].elemento[0].naipeC);
					scanf("%d",&resposta);
					if(resposta == 1){
						MESA = reset(MESA, Baralho, linha, coluna, carta);
						MESA = gatilho(MESA, linha, coluna);
						bool = 1;
					}
					else if(resposta == 2){
					printf("\nEsta carta tem o valor menor do que a %d%c",MESA.mesa[linha][coluna].elemento[0].valor, MESA.mesa[linha][coluna].elemento[0].naipeC);
					printf("\nDigite outra posição...\n");
					}
					else{printf("Resposta inválida");}
				}

				else{
					int i;

					for(i=18;i>=0;i--){
						MESA.mesa[linha][coluna].elemento[i+1].valor = MESA.mesa[linha][coluna].elemento[i].valor;
						MESA.mesa[linha][coluna].elemento[i+1].naipe = MESA.mesa[linha][coluna].elemento[i].naipe;
						MESA.mesa[linha][coluna].elemento[i+1].naipeC = MESA.mesa[linha][coluna].elemento[i].naipeC;
					}

					if (linha == 2){
						MESA.mesa[0][coluna+2-4].elemento[0].valor++;
					}

					if (linha == 3){
											MESA.mesa[0][coluna+2-4].elemento[1].valor++;
										}

					if (linha == 4){
											MESA.mesa[0][coluna+2-4].elemento[2].valor++;
										}

					MESA.mesa[linha][coluna].elemento[0].valor = carta.valor;
					MESA.mesa[linha][coluna].elemento[0].naipe = carta.naipe;
					MESA.mesa[linha][coluna].elemento[0].naipeC = carta.naipeC;
					MESA.mesa[5][1].elemento[1].valor++; //k++
					MESA = gatilho(MESA, linha, coluna);
					bool = 1;
				}
			}
		}
	}
	return(MESA);
}

tipoMesa gatilho(tipoMesa MESA, int linha, int coluna){
	if(linha == 2 && coluna == 2){
		if(MESA.mesa[2][5].elemento[0].valor != 0){
			if(MESA.mesa[2][5].elemento[0].valor == 13){
				if((MESA.mesa[2][3].elemento[0].naipe == MESA.mesa[2][5].elemento[0].naipe)&&(MESA.mesa[2][4].elemento[0].naipe == MESA.mesa[2][5].elemento[0].naipe)){
					if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[2][4].elemento[0].valor) >= MESA.mesa[2][5].elemento[0].valor){
						printf("Rei MORTO!\n");
						MESA.mesa[2][5].elemento[0].valor = 0;
						MESA.mesa[2][5].elemento[0].naipe = -1;
						MESA.mesa[2][5].elemento[0].naipeC = 'X';
						MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
					}
				}
			}
			if(MESA.mesa[2][5].elemento[0].valor == 12){
				if(MESA.mesa[2][5].elemento[0].naipe%2 == 0){
					if((MESA.mesa[2][3].elemento[0].naipe%2 == 0)&&(MESA.mesa[2][4].elemento[0].naipe%2 == 0)){
						if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[2][4].elemento[0].valor) >= MESA.mesa[2][5].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[2][5].elemento[0].valor = 0;
							MESA.mesa[2][5].elemento[0].naipe = -1;
							MESA.mesa[2][5].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
				}
			}
	       }
				else{
					if((MESA.mesa[2][3].elemento[0].naipe%2 != 0)&&(MESA.mesa[2][4].elemento[0].naipe%2 != 0)){
							if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[2][4].elemento[0].valor) >= MESA.mesa[2][5].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[2][5].elemento[0].valor = 0;
							MESA.mesa[2][5].elemento[0].naipe = -1;
							MESA.mesa[2][5].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				 }
		   }
			if(MESA.mesa[2][5].elemento[0].valor == 11){
					if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[2][4].elemento[0].valor) >= MESA.mesa[2][5].elemento[0].valor){
					printf("Valete MORTO!\n");
					MESA.mesa[2][5].elemento[0].valor = 0;
					MESA.mesa[2][5].elemento[0].naipe = -1;
					MESA.mesa[2][5].elemento[0].naipeC = 'X';
					MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
		}
			if(MESA.mesa[5][2].elemento[0].valor == 13){
							if((MESA.mesa[4][2].elemento[0].naipe == MESA.mesa[5][2].elemento[0].naipe)&&(MESA.mesa[3][2].elemento[0].naipe == MESA.mesa[5][2].elemento[0].naipe)){
								if((MESA.mesa[4][2].elemento[0].valor + MESA.mesa[3][2].elemento[0].valor) >= MESA.mesa[5][2].elemento[0].valor){
									printf("Rei MORTO!\n");
									MESA.mesa[5][2].elemento[0].valor = 0;
									MESA.mesa[5][2].elemento[0].naipe = -1;
									MESA.mesa[5][2].elemento[0].naipeC = 'X';
									MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
						}
						if(MESA.mesa[5][2].elemento[0].valor == 12){
							if(MESA.mesa[5][2].elemento[0].naipe%2 == 0){
								if((MESA.mesa[4][2].elemento[0].naipe%2 == 0)&&(MESA.mesa[3][2].elemento[0].naipe%2 == 0)){
									if((MESA.mesa[4][2].elemento[0].valor + MESA.mesa[3][2].elemento[0].valor) >= MESA.mesa[5][2].elemento[0].valor){
										printf("Rainha MORTA!\n");
										MESA.mesa[5][2].elemento[0].valor = 0;
										MESA.mesa[5][2].elemento[0].naipe = -1;
										MESA.mesa[5][2].elemento[0].naipeC = 'X';
										MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				       }
							else{
								if((MESA.mesa[4][2].elemento[0].naipe%2 != 0)&&(MESA.mesa[3][2].elemento[0].naipe%2 != 0)){
										if((MESA.mesa[4][2].elemento[0].valor + MESA.mesa[3][2].elemento[0].valor) >= MESA.mesa[5][2].elemento[0].valor){
										printf("Rainha MORTA!\n");
										MESA.mesa[5][2].elemento[0].valor = 0;
										MESA.mesa[5][2].elemento[0].naipe = -1;
										MESA.mesa[5][2].elemento[0].naipeC = 'X';
										MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
										}
									}
							 }
					   }
						if(MESA.mesa[5][2].elemento[0].valor == 11){
								if((MESA.mesa[4][2].elemento[0].valor + MESA.mesa[3][2].elemento[0].valor) >= MESA.mesa[5][2].elemento[0].valor){
								printf("Valete MORTO!\n");
								MESA.mesa[5][2].elemento[0].valor = 0;
								MESA.mesa[5][2].elemento[0].naipe = -1;
								MESA.mesa[5][2].elemento[0].naipeC = 'X';
								MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
											}
										}
	 }



	if(linha == 2 && coluna == 4){
		if(MESA.mesa[2][1].elemento[0].valor != 0)
		{
			if(MESA.mesa[2][1].elemento[0].valor == 13){
				if((MESA.mesa[2][3].elemento[0].naipe == MESA.mesa[2][1].elemento[0].naipe)&&(MESA.mesa[2][2].elemento[0].naipe == MESA.mesa[2][1].elemento[0].naipe)){
					if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[2][2].elemento[0].valor) >= MESA.mesa[2][1].elemento[0].valor){
						printf("Rei MORTO!\n");
						MESA.mesa[2][1].elemento[0].valor = 0;
						MESA.mesa[2][1].elemento[0].naipe = -1;
						MESA.mesa[2][1].elemento[0].naipeC = 'X';
						MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
					}
				}
			}
			if(MESA.mesa[2][1].elemento[0].valor == 12){
				if(MESA.mesa[2][1].elemento[0].naipe%2 == 0){
					if((MESA.mesa[2][3].elemento[0].naipe%2 == 0)&&(MESA.mesa[2][2].elemento[0].naipe%2 == 0)){
						if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[2][2].elemento[0].valor) >= MESA.mesa[2][1].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[2][1].elemento[0].valor = 0;
							MESA.mesa[2][1].elemento[0].naipe = -1;
							MESA.mesa[2][1].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
				}
			}
	       }
				else{
					if((MESA.mesa[2][3].elemento[0].naipe%2 != 0)&&(MESA.mesa[2][2].elemento[0].naipe%2 != 0)){
							if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[2][2].elemento[0].valor) >= MESA.mesa[2][1].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[2][1].elemento[0].valor = 0;
							MESA.mesa[2][1].elemento[0].naipe = -1;
							MESA.mesa[2][1].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				 }
		   }
			if(MESA.mesa[2][1].elemento[0].valor == 11){
					if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[2][2].elemento[0].valor) >= MESA.mesa[2][1].elemento[0].valor){
					printf("Valete MORTO!\n");
					MESA.mesa[2][1].elemento[0].valor = 0;
					MESA.mesa[2][1].elemento[0].naipe = -1;
					MESA.mesa[2][1].elemento[0].naipeC = 'X';
					MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
		}
			if(MESA.mesa[5][4].elemento[0].valor == 13){
							if((MESA.mesa[4][4].elemento[0].naipe == MESA.mesa[5][4].elemento[0].naipe)&&(MESA.mesa[3][4].elemento[0].naipe == MESA.mesa[5][4].elemento[0].naipe)){
								if((MESA.mesa[4][4].elemento[0].valor + MESA.mesa[3][4].elemento[0].valor) >= MESA.mesa[5][4].elemento[0].valor){
									printf("Rei MORTO!\n");
									MESA.mesa[5][4].elemento[0].valor = 0;
									MESA.mesa[5][4].elemento[0].naipe = -1;
									MESA.mesa[5][4].elemento[0].naipeC = 'X';
									MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
						}
						if(MESA.mesa[5][4].elemento[0].valor == 12){
							if(MESA.mesa[5][4].elemento[0].naipe%2 == 0){
								if((MESA.mesa[4][4].elemento[0].naipe%2 == 0)&&(MESA.mesa[3][4].elemento[0].naipe%2 == 0)){
									if((MESA.mesa[4][4].elemento[0].valor + MESA.mesa[3][4].elemento[0].valor) >= MESA.mesa[5][4].elemento[0].valor){
										printf("Rainha MORTA!\n");
										MESA.mesa[5][4].elemento[0].valor = 0;
										MESA.mesa[5][4].elemento[0].naipe = -1;
										MESA.mesa[5][4].elemento[0].naipeC = 'X';
										MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				       }
							else{
								if((MESA.mesa[4][4].elemento[0].naipe%2 != 0)&&(MESA.mesa[3][4].elemento[0].naipe%2 != 0)){
										if((MESA.mesa[4][4].elemento[0].valor + MESA.mesa[3][4].elemento[0].valor) >= MESA.mesa[5][4].elemento[0].valor){
										printf("Rainha MORTA!\n");
										MESA.mesa[5][4].elemento[0].valor = 0;
										MESA.mesa[5][4].elemento[0].naipe = -1;
										MESA.mesa[5][4].elemento[0].naipeC = 'X';
										MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
										}
									}
							 }
					   }
						if(MESA.mesa[5][4].elemento[0].valor == 11){
								if((MESA.mesa[4][4].elemento[0].valor + MESA.mesa[3][4].elemento[0].valor) >= MESA.mesa[5][4].elemento[0].valor){
								printf("Valete MORTO!\n");
								MESA.mesa[5][4].elemento[0].valor = 0;
								MESA.mesa[5][4].elemento[0].naipe = -1;
								MESA.mesa[5][4].elemento[0].naipeC = 'X';
								MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
											}
										}
	 }




	if(linha == 4 && coluna == 2){
		if(MESA.mesa[4][5].elemento[0].valor != 0){
			if(MESA.mesa[4][5].elemento[0].valor == 13){
				if((MESA.mesa[4][3].elemento[0].naipe == MESA.mesa[4][5].elemento[0].naipe)&&(MESA.mesa[4][4].elemento[0].naipe == MESA.mesa[4][5].elemento[0].naipe)){
					if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[4][4].elemento[0].valor) >= MESA.mesa[4][5].elemento[0].valor){
						printf("Rei MORTO!\n");
						MESA.mesa[4][5].elemento[0].valor = 0;
						MESA.mesa[4][5].elemento[0].naipe = -1;
						MESA.mesa[4][5].elemento[0].naipeC = 'X';
						MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
					}
				}
			}
			if(MESA.mesa[4][5].elemento[0].valor == 12){
				if(MESA.mesa[4][5].elemento[0].naipe%2 == 0){
					if((MESA.mesa[4][3].elemento[0].naipe%2 == 0)&&(MESA.mesa[4][4].elemento[0].naipe%2 == 0)){
						if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[4][4].elemento[0].valor) >= MESA.mesa[4][5].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[4][5].elemento[0].valor = 0;
							MESA.mesa[4][5].elemento[0].naipe = -1;
							MESA.mesa[4][5].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
				}
			}
	       }
				else{
					if((MESA.mesa[4][3].elemento[0].naipe%2 != 0)&&(MESA.mesa[4][4].elemento[0].naipe%2 != 0)){
							if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[4][4].elemento[0].valor) >= MESA.mesa[4][5].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[4][5].elemento[0].valor = 0;
							MESA.mesa[4][5].elemento[0].naipe = -1;
							MESA.mesa[4][5].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				 }
		   }
			if(MESA.mesa[4][5].elemento[0].valor == 11){
					if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[4][4].elemento[0].valor) >= MESA.mesa[4][5].elemento[0].valor){
					printf("Valete MORTO!\n");
					MESA.mesa[4][5].elemento[0].valor = 0;
					MESA.mesa[4][5].elemento[0].naipe = -1;
					MESA.mesa[4][5].elemento[0].naipeC = 'X';
					MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
		}
			if(MESA.mesa[1][2].elemento[0].valor == 13){
							if((MESA.mesa[3][2].elemento[0].naipe == MESA.mesa[1][2].elemento[0].naipe)&&(MESA.mesa[2][2].elemento[0].naipe == MESA.mesa[1][2].elemento[0].naipe)){
								if((MESA.mesa[3][2].elemento[0].valor + MESA.mesa[2][2].elemento[0].valor) >= MESA.mesa[1][2].elemento[0].valor){
									printf("Rei MORTO!\n");
									MESA.mesa[1][2].elemento[0].valor = 0;
									MESA.mesa[1][2].elemento[0].naipe = -1;
									MESA.mesa[1][2].elemento[0].naipeC = 'X';
									MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
						}
						if(MESA.mesa[1][2].elemento[0].valor == 12){
							if(MESA.mesa[1][2].elemento[0].naipe%2 == 0){
								if((MESA.mesa[2][2].elemento[0].naipe%2 == 0)&&(MESA.mesa[3][2].elemento[0].naipe%2 == 0)){
									if((MESA.mesa[2][2].elemento[0].valor + MESA.mesa[3][2].elemento[0].valor) >= MESA.mesa[1][2].elemento[0].valor){
										printf("Rainha MORTA!\n");
										MESA.mesa[1][2].elemento[0].valor = 0;
										MESA.mesa[1][2].elemento[0].naipe = -1;
										MESA.mesa[1][2].elemento[0].naipeC = 'X';
										MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				       }
							else{
								if((MESA.mesa[3][2].elemento[0].naipe%2 != 0)&&(MESA.mesa[2][2].elemento[0].naipe%2 != 0)){
										if((MESA.mesa[3][2].elemento[0].valor + MESA.mesa[2][2].elemento[0].valor) >= MESA.mesa[1][2].elemento[0].valor){
										printf("Rainha MORTA!\n");
										MESA.mesa[1][2].elemento[0].valor = 0;
										MESA.mesa[1][2].elemento[0].naipe = -1;
										MESA.mesa[1][2].elemento[0].naipeC = 'X';
										MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
										}
									}
							 }
					   }
						if(MESA.mesa[1][2].elemento[0].valor == 11){
								if((MESA.mesa[2][2].elemento[0].valor + MESA.mesa[3][2].elemento[0].valor) >= MESA.mesa[1][2].elemento[0].valor){
								printf("Valete MORTO!\n");
								MESA.mesa[1][2].elemento[0].valor = 0;
								MESA.mesa[2][2].elemento[0].naipe = -1;
								MESA.mesa[1][2].elemento[0].naipeC = 'X';
								MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
											}
										}
	 }




	if(linha == 4 && coluna == 4){
		if(MESA.mesa[4][1].elemento[0].valor != 0){
			if(MESA.mesa[4][1].elemento[0].valor == 13){
				if((MESA.mesa[4][3].elemento[0].naipe == MESA.mesa[4][1].elemento[0].naipe)&&(MESA.mesa[4][2].elemento[0].naipe == MESA.mesa[4][1].elemento[0].naipe)){
					if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[4][2].elemento[0].valor) >= MESA.mesa[4][1].elemento[0].valor){
						printf("Rei MORTO!\n");
						MESA.mesa[4][1].elemento[0].valor = 0;
						MESA.mesa[4][1].elemento[0].naipe = -1;
						MESA.mesa[4][1].elemento[0].naipeC = 'X';
						MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
					}
				}
			}
			if(MESA.mesa[4][1].elemento[0].valor == 12){
				if(MESA.mesa[4][1].elemento[0].naipe%2 == 0){
					if((MESA.mesa[4][3].elemento[0].naipe%2 == 0)&&(MESA.mesa[4][2].elemento[0].naipe%2 == 0)){
						if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[4][2].elemento[0].valor) >= MESA.mesa[4][1].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[4][1].elemento[0].valor = 0;
							MESA.mesa[4][1].elemento[0].naipe = -1;
							MESA.mesa[4][1].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
				}
			}
	       }
				else{
					if((MESA.mesa[4][3].elemento[0].naipe%2 != 0)&&(MESA.mesa[4][2].elemento[0].naipe%2 != 0)){
							if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[4][2].elemento[0].valor) >= MESA.mesa[4][1].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[4][1].elemento[0].valor = 0;
							MESA.mesa[4][1].elemento[0].naipe = -1;
							MESA.mesa[4][1].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				 }
		   }
			if(MESA.mesa[4][1].elemento[0].valor == 11){
					if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[4][2].elemento[0].valor) >= MESA.mesa[4][1].elemento[0].valor){
					printf("Valete MORTO!\n");
					MESA.mesa[4][1].elemento[0].valor = 0;
					MESA.mesa[4][1].elemento[0].naipe = -1;
					MESA.mesa[4][1].elemento[0].naipeC = 'X';
					MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
		}
			if(MESA.mesa[1][4].elemento[0].valor == 13){
							if((MESA.mesa[3][4].elemento[0].naipe == MESA.mesa[1][4].elemento[0].naipe)&&(MESA.mesa[2][4].elemento[0].naipe == MESA.mesa[1][4].elemento[0].naipe)){
								if((MESA.mesa[3][4].elemento[0].valor + MESA.mesa[2][4].elemento[0].valor) >= MESA.mesa[1][4].elemento[0].valor){
									printf("Rei MORTO!\n");
									MESA.mesa[1][4].elemento[0].valor = 0;
									MESA.mesa[1][4].elemento[0].naipe = -1;
									MESA.mesa[1][4].elemento[0].naipeC = 'X';
									MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
						}
						if(MESA.mesa[1][4].elemento[0].valor == 12){
							if(MESA.mesa[1][4].elemento[0].naipe%2 == 0){
								if((MESA.mesa[2][4].elemento[0].naipe%2 == 0)&&(MESA.mesa[3][4].elemento[0].naipe%2 == 0)){
									if((MESA.mesa[2][4].elemento[0].valor + MESA.mesa[3][4].elemento[0].valor) >= MESA.mesa[1][4].elemento[0].valor){
										printf("Rainha MORTA!\n");
										MESA.mesa[1][4].elemento[0].valor = 0;
										MESA.mesa[1][4].elemento[0].naipe = -1;
										MESA.mesa[1][4].elemento[0].naipeC = 'X';
										MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				       }
							else{
								if((MESA.mesa[2][4].elemento[0].naipe%2 != 0)&&(MESA.mesa[3][4].elemento[0].naipe%2 != 0)){
										if((MESA.mesa[2][4].elemento[0].valor + MESA.mesa[3][4].elemento[0].valor) >= MESA.mesa[1][4].elemento[0].valor){
										printf("Rainha MORTA!\n");
										MESA.mesa[1][4].elemento[0].valor = 0;
										MESA.mesa[1][4].elemento[0].naipe = -1;
										MESA.mesa[1][4].elemento[0].naipeC = 'X';
										MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
										}
									}
							 }
					   }
						if(MESA.mesa[1][4].elemento[0].valor == 11){
								if((MESA.mesa[2][4].elemento[0].valor + MESA.mesa[3][4].elemento[0].valor) >= MESA.mesa[1][4].elemento[0].valor){
								printf("Valete MORTO!\n");
								MESA.mesa[1][4].elemento[0].valor = 0;
								MESA.mesa[1][4].elemento[0].naipe = -1;
								MESA.mesa[1][4].elemento[0].naipeC = 'X';
								MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
											}
										}
	 }




   if(linha == 2 && coluna == 3){
		if(MESA.mesa[5][3].elemento[0].valor != 0){
			if(MESA.mesa[5][3].elemento[0].valor == 13){
				if((MESA.mesa[4][3].elemento[0].naipe == MESA.mesa[5][3].elemento[0].naipe)&&(MESA.mesa[3][3].elemento[0].naipe == MESA.mesa[5][3].elemento[0].naipe)){
					if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[5][3].elemento[0].valor){
						printf("Rei MORTO!\n");
						MESA.mesa[5][3].elemento[0].valor = 0;
						MESA.mesa[5][3].elemento[0].naipe = -1;
						MESA.mesa[5][3].elemento[0].naipeC = 'X';
						MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
					}
				}
			}
			if(MESA.mesa[5][3].elemento[0].valor == 12){
				if(MESA.mesa[5][3].elemento[0].naipe%2 == 0){
					if((MESA.mesa[4][3].elemento[0].naipe%2 == 0)&&(MESA.mesa[3][3].elemento[0].naipe%2 == 0)){
						if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[5][3].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[5][3].elemento[0].valor = 0;
							MESA.mesa[5][3].elemento[0].naipe = -1;
							MESA.mesa[5][3].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
				}
			}
	       }
				else{
					if((MESA.mesa[4][3].elemento[0].naipe%2 != 0)&&(MESA.mesa[3][3].elemento[0].naipe%2 != 0)){
							if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[5][3].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[5][3].elemento[0].valor = 0;
							MESA.mesa[5][3].elemento[0].naipe = -1;
							MESA.mesa[5][3].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				 }
		   }
			if(MESA.mesa[5][3].elemento[0].valor == 11){
					if((MESA.mesa[4][3].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[5][3].elemento[0].valor){
					printf("Valete MORTO!\n");
					MESA.mesa[5][3].elemento[0].valor = 0;
					MESA.mesa[5][3].elemento[0].naipe = -1;
					MESA.mesa[5][3].elemento[0].naipeC = 'X';
					MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
	 }
	}


   if(linha == 4 && coluna == 3){
		if(MESA.mesa[1][3].elemento[0].valor != 0){
			if(MESA.mesa[1][3].elemento[0].valor == 13){
				if((MESA.mesa[2][3].elemento[0].naipe == MESA.mesa[1][3].elemento[0].naipe)&&(MESA.mesa[3][3].elemento[0].naipe == MESA.mesa[1][3].elemento[0].naipe)){
					if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[1][3].elemento[0].valor){
						printf("Rei MORTO!\n");
						MESA.mesa[1][3].elemento[0].valor = 0;
						MESA.mesa[1][3].elemento[0].naipe = -1;
						MESA.mesa[1][3].elemento[0].naipeC = 'X';
						MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
					}
				}
			}
			if(MESA.mesa[1][3].elemento[0].valor == 12){
				if(MESA.mesa[1][3].elemento[0].naipe%2 == 0){
					if((MESA.mesa[2][3].elemento[0].naipe%2 == 0)&&(MESA.mesa[3][3].elemento[0].naipe%2 == 0)){
						if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[1][3].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[1][3].elemento[0].valor = 0;
							MESA.mesa[1][3].elemento[0].naipe = -1;
							MESA.mesa[1][3].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
				}
			}
	       }
				else{
					if((MESA.mesa[2][3].elemento[0].naipe%2 != 0)&&(MESA.mesa[3][3].elemento[0].naipe%2 != 0)){
							if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[1][3].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[1][3].elemento[0].valor = 0;
							MESA.mesa[1][3].elemento[0].naipe = -1;
							MESA.mesa[1][3].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				 }
		   }
			if(MESA.mesa[1][3].elemento[0].valor == 11){
					if((MESA.mesa[2][3].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[1][3].elemento[0].valor){
					printf("Valete MORTO!\n");
					MESA.mesa[1][3].elemento[0].valor = 0;
					MESA.mesa[1][3].elemento[0].naipe = -1;
					MESA.mesa[1][3].elemento[0].naipeC = 'X';
					MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
	 }
	}




if(linha == 3 && coluna == 2){
		if(MESA.mesa[3][5].elemento[0].valor != 0){
			if(MESA.mesa[3][5].elemento[0].valor == 13){
				if((MESA.mesa[3][4].elemento[0].naipe == MESA.mesa[3][5].elemento[0].naipe)&&(MESA.mesa[3][3].elemento[0].naipe == MESA.mesa[3][5].elemento[0].naipe)){
					if((MESA.mesa[3][4].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[3][5].elemento[0].valor){
						printf("Rei MORTO!\n");
						MESA.mesa[3][5].elemento[0].valor = 0;
						MESA.mesa[3][5].elemento[0].naipe = -1;
						MESA.mesa[3][5].elemento[0].naipeC = 'X';
						MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
					}
				}
			}
			if(MESA.mesa[3][5].elemento[0].valor == 12){
				if(MESA.mesa[3][5].elemento[0].naipe%2 == 0){
					if((MESA.mesa[3][4].elemento[0].naipe%2 == 0)&&(MESA.mesa[3][3].elemento[0].naipe%2 == 0)){
						if((MESA.mesa[3][4].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[3][5].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[3][5].elemento[0].valor = 0;
							MESA.mesa[3][5].elemento[0].naipe = -1;
							MESA.mesa[3][5].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
				}
			}
	       }
				else{
					if((MESA.mesa[3][4].elemento[0].naipe%2 != 0)&&(MESA.mesa[3][3].elemento[0].naipe%2 != 0)){
							if((MESA.mesa[3][4].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[3][5].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[3][5].elemento[0].valor = 0;
							MESA.mesa[3][5].elemento[0].naipe = -1;
							MESA.mesa[3][5].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				 }
		   }
			if(MESA.mesa[3][5].elemento[0].valor == 11){
					if((MESA.mesa[3][4].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[3][5].elemento[0].valor){
					printf("Valete MORTO!\n");
					MESA.mesa[3][5].elemento[0].valor = 0;
					MESA.mesa[3][5].elemento[0].naipe = -1;
					MESA.mesa[3][5].elemento[0].naipeC = 'X';
					MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
	 }
	}




if(linha == 3 && coluna == 4){
		if(MESA.mesa[3][1].elemento[0].valor != 0){
			if(MESA.mesa[3][1].elemento[0].valor == 13){
				if((MESA.mesa[3][2].elemento[0].naipe == MESA.mesa[3][1].elemento[0].naipe)&&(MESA.mesa[3][3].elemento[0].naipe == MESA.mesa[3][1].elemento[0].naipe)){
					if((MESA.mesa[3][2].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[3][1].elemento[0].valor){
						printf("Rei MORTO!\n");
						MESA.mesa[3][1].elemento[0].valor = 0;
						MESA.mesa[3][1].elemento[0].naipe = -1;
						MESA.mesa[3][1].elemento[0].naipeC = 'X';
						MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
					}
				}
			}
			if(MESA.mesa[3][1].elemento[0].valor == 12){
				if(MESA.mesa[3][1].elemento[0].naipe%2 == 0){
					if((MESA.mesa[3][2].elemento[0].naipe%2 == 0)&&(MESA.mesa[3][3].elemento[0].naipe%2 == 0)){
						if((MESA.mesa[3][2].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[3][1].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[3][1].elemento[0].valor = 0;
							MESA.mesa[3][1].elemento[0].naipe = -1;
							MESA.mesa[3][1].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
				}
			}
	       }
				else{
					if((MESA.mesa[3][2].elemento[0].naipe%2 != 0)&&(MESA.mesa[3][3].elemento[0].naipe%2 != 0)){
							if((MESA.mesa[3][2].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[3][1].elemento[0].valor){
							printf("Rainha MORTA!\n");
							MESA.mesa[3][1].elemento[0].valor = 0;
							MESA.mesa[3][1].elemento[0].naipe = -1;
							MESA.mesa[3][1].elemento[0].naipeC = 'X';
							MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
							}
						}
				 }
		   }
			if(MESA.mesa[3][1].elemento[0].valor == 11){
					if((MESA.mesa[3][2].elemento[0].valor + MESA.mesa[3][3].elemento[0].valor) >= MESA.mesa[3][1].elemento[0].valor){
					printf("Valete MORTO!\n");
					MESA.mesa[3][1].elemento[0].valor = 0;
					MESA.mesa[3][1].elemento[0].naipe = -1;
					MESA.mesa[3][1].elemento[0].naipeC = 'X';
					MESA.mesa[5][5].elemento[1].valor = MESA.mesa[5][5].elemento[1].valor -1;
								}
							}
	 }
	}

	return(MESA);
 }
