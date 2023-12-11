#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#include <stdio.h>
#include <conio.h>
#include "dataStructures.h"

void freeCharMatrix(char** matrix, int x, int y) {
	// this function frees all the allocated memory of the playerTable and hitMap (called separetly)
	for (int i = 0; i < x; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void renderMap(char** map, int dim) {
	// this functin prints any of the players two maps based on the playing fields length
	if (dim > 10) {
		for (int i = 0; i < dim; i++) {

			if (i == 0) {

				printf("\t    ");
				for (int j = 0; j < dim; j++) {
					if (j < 9) printf("%d  ", j + 1);
					else printf("%d ", j + 1);
					if (j == dim - 1) printf("\n\n");
				}

			}

			printf("\t");

			if (dim < 10) {
				for (int j = 0; j < dim; j++) {
					if (j == 0) printf("%d  ", i + 1);
					if (map[i][j] == 'X') {
						printf("\033[31;1m %c\033[0m", map[i][j]);
					}
					else if (map[i][j] == 'O') {
						printf("\033[90;1m %c\033[0m", map[i][j]);
					}
					else if (map[i][j] == 'H') {
						printf("\033[37;1m %c\033[0m", map[i][j]);
					}
					else {
						printf("\033[36;1m %c\033[0m", map[i][j]);
					}
				}
			}
			else {

				for (int j = 0; j < dim; j++) {
					if (j == 0) {
						printf("%d ", i + 1);
						if (i < 9) printf(" ");
					}
					if (map[i][j] == 'X') {
						printf("\033[31;1m %c\033[0m", map[i][j]);
					}
					else if (map[i][j] == 'O') {
						printf("\033[90;1m %c\033[0m", map[i][j]);
					}
					else if (map[i][j] == 'H') {
						printf("\033[37;1m %c\033[0m", map[i][j]);
					}
					else {
						printf("\033[36;1m %c\033[0m", map[i][j]);
					}
				}

			}
			printf("\n\n");
		}
		printf("\n\n\n");
	}
	else {
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
					if (map[i][j] == 'X') {
						printf("\033[31;1m %c\033[0m", map[i][j]);
					}
					else if (map[i][j] == 'O') {
						printf("\033[90;1m %c\033[0m", map[i][j]);
					}
					else if (map[i][j] == 'H') {
						printf("\033[37;1m %c\033[0m", map[i][j]);
					}
					else {
						printf("\033[36;1m %c\033[0m", map[i][j]);
					}
				}
			}
			else {

				for (int j = 0; j < dim; j++) {
					if (j == 0) {
						printf("%d ", i + 1);
						if (i < 9) printf(" ");
					}
					if (map[i][j] == 'X') {
						printf("\033[31;1m %c\033[0m", map[i][j]);
					}
					else if (map[i][j] == 'O') {
						printf("\033[90;1m %c\033[0m", map[i][j]);
					}
					else if (map[i][j] == 'H') {
						printf("\033[37;1m %c\033[0m", map[i][j]);
					}
					else {
						printf("\033[36;1m %c\033[0m", map[i][j]);
					}
				}

			}
			printf("\n");
		}
		printf("\n\n\n");
	}
}

void updateIncompleteMap(Player* player, int limit) {
	// This function updates the players table to a point (limit) so it doesn't read any
	// unallocated memory
	for (int i = 0; i < limit; i++) {
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

void updatePlayerTable(Player* player) {
	// This fucntion updates the player's table when all of the ships already allocated, as it
	// goes through fully on player.ships array 
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
	// This function swithches the place of the two players, so the previously attacking player will become the target in
	// the next round
	Player temp = playerArray[0];
	playerArray[0] = playerArray[1];
	playerArray[1] = temp;
}

int isGameOver(Player* enemy) {
	// this function checks if the targeted enemy has left any active ships
	// if it has the function returns 0, else 0 
	int i = 0;
	while (i < enemy->numberOfShips && enemy->ships[i].state != 1) {
		i++;
	}

	if (i >= enemy->numberOfShips) {
		return 1;
	}
	else return 0;
}

#endif