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

int isShipValid(int x, int y, int ori, int size, int dim, Ship* ships) {
	if (ori != 2 || x > 0 || x + (size - 1) > dim || y < 0 && ori != 2 && x > 0 && x + (size - 1) > dim && y < 0) // Continue from here
}

Ship* getShips(int numS, int dim) {
	Ship* shipArray = (Ship*)malloc(sizeof(Ship) * numS);

	for (int i = numS; i > 0; i--) {
		Ship shipInsatance;

		int x, y, orientation;

		do
		{
			printf("Orientation of the ships (1: vertical | 2: horizontal): ");
			scanf("%D", &orientation);
			printf("X starting coordinate: ");
			scanf("%d", &x);
			printf("Y starting coordinate", &y);


		} while ();
	}
}

void InitializePlayers(Player* player1, int dimension, int numOfShips) {
	player1->playerTable = AllocateCharMatrix(dimension, dimension);

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			player1->playerTable[i][j] = '#';
		}
	}
}

#endif