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

int isShipValid(int x, int y, int ori, int size, int dim) {
	if (ori == 1) {
		if (y + size <= dim && y > 0 && x <= dim && x > 0) return 1;
	}
	else if (ori == 2) {
		if (y <= dim && y > 0 && x + size <= dim && x > 0) return 1;
	}

	return 0;
}

int willShipCollide(int x, int y, int size, int ori, Ship* ships) {
	Field* shipsFields = getShipsFields(x, y, size, ori);
	for (int i = 0; i < size; i++) {
		for (int j )  // folyt. köv.
	}
}

Field* getShipsFields(int starterX, int starterY, int size, int orientation) {
	Field* fields = (Field*)malloc(sizeof(Field) * size);
	if (orientation == 1) {
		for (int i = 0; i < size; i++) {
			Field fieldInstance;
			fieldInstance.x = starterX;
			fieldInstance.y = starterY + i;
			fields[i] = fieldInstance;
		}

		return fields;
	}
	else if (orientation == 2) {
		for (int i = 0; i < size; i++) {
			Field fieldInstance;
			fieldInstance.x = starterX + i;
			fieldInstance.y = starterY;
			fields[i] = fieldInstance;
		}

		return fields;
	}

	return fields;
}

Ship* getShips(int numS, int dim, int maxLength) {
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