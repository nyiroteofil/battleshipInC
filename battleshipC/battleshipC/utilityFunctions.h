#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#include <stdio.h>
#include <conio.h>
#include "dataStructures.h"

void renderPlayerMap(Player* player, int dim) {
	printf("Players map : \n");
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
				printf(" %c", player->playerTable[i][j]);
			}
		}
		else {

			for (int j = 0; j < dim; j++) {
				if (j == 0) {
					printf("%d ", i + 1);
					if (i != dim - 1) printf(" ");
				}
				printf(" %c", player->playerTable[i][j]);
			}

		}
		printf("\n");
	}
	printf("\n\n");
}

void updatePlayerTable(Player* player, int shipNum) {
	for (int i = 0; i < shipNum; i++) {
		for (int j = 0; j < player->ships[i].size; j++) {
			player->playerTable[player->ships[i].occupiedFields[j].x][player->ships[i].occupiedFields[j].y] = 'H';
		}
	}
}

#endif