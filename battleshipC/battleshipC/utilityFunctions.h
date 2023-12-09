#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#include <stdio.h>
#include <conio.h>
#include "dataStructures.h"

void renderMap(char** map, int dim) {
	for (int i = 0; i < dim; i++) {
		
		if (i == 0) {

			printf("\t    ");
			for (int j = 0; j < dim; j++) {
					printf("%d ", j + 1);
					if (j == dim - 1) printf("\n\n");
			}

		}

		printf("\t");

		if (dim < 10) {
			for (int j = 0; j < dim; j++) {
				if (j == 0) printf("%d  ", i + 1);
				printf(" %c", map[i][j]);
			}
		}
		else {

			for (int j = 0; j < dim; j++) {
				if (j == 0) {
					printf("%d ", i + 1);
					if (i != dim - 1) printf(" ");
				}
				printf(" %c", map[i][j]);
			}

		}
		printf("\n");
	}
	printf("\n\n");
}

void updatePlayerTable(Player* player) {
	for (int i = 0; i < player->numberOfShips; i++) {
		for (int j = 0; j < player->ships[i].size; j++) {
			int x = player->ships[i].occupiedFields[j].x;
			int y = player->ships[i].occupiedFields[j].y;
			int state = player->ships[i].occupiedFields[j].state;
			if (state == 1) {
				player->playerTable[x][y] = 'H';
			}
			else {
				player->playerTable[x][y] = 'X';
			}
		}
	}
}

void switchPlayers(Player* playerArray) {
	Player temp = playerArray[0];
	playerArray[0] = playerArray[1];
	playerArray[0] = temp;
}

#endif