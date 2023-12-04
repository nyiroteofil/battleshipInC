#ifndef BATTLESIHIPFUNCTIONS_H
#define BATTLESIPFUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "dataStructures.h"

typedef struct Player Player;
typedef struct Ship Ship;
typedef struct Field Field;

char** AllocateCharMatrix(int sizeX, int sizeY) {
	char** matrix = (char**)malloc(sizeof(char*) * sizeY);
	for (int i = 0; i < sizeX; i++) {
		matrix[i] = (char*)malloc(sizeof(char) * sizeX);
	}

	return matrix;
}

void InitializePlayers(Player* player1, int dimension, int numOfShips) {
	player1->playerTable = AllocateCharMatrix(dimension, dimension);

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			player1->playerTable[i][j] = '#';
		}
	}

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			printf("%c ", player1->playerTable[i][j]);
		}
		printf("\n");
	}
}

#endif