#ifndef BATTLESIHIPFUNCTIONS_H
#define BATTLESIPFUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "dataStructures.h"
#include "utilityFunctions.h"

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
	size -= 1;
	if (ori == 2) {
		if (y + size < dim && y > -1 && x <= dim && x > -1) return 1;
	}
	else if (ori == 1) {
		if (y <= dim && y > -1 && x - size < dim && x > -1) return 1;
	}

	printf("!!! Invalid ship placement: Invalid Coordinates !!!\n\n");
	return 0;
}


Field* getShipsFields(int starterX, int starterY, int size, int orientation) {
	Field* fields = (Field*)malloc(sizeof(Field) * size);
	if (orientation == 1) {
		for (int i = 0; i < size; i++) {
			Field fieldInstance;
			fieldInstance.x = starterX - i;
			fieldInstance.y = starterY;
			fieldInstance.state = 1;
			fields[i] = fieldInstance;
		}

		return fields;
	}
	else if (orientation == 2) {
		for (int i = 0; i < size; i++) {
			Field fieldInstance;
			fieldInstance.x = starterX;
			fieldInstance.y = starterY + i;
			fields[i] = fieldInstance;
		}

		return fields;
	}

	return fields;
}

int willShipCollide(int x, int y, int size, int ori, Ship* ships) {
	Field* shipsFields = getShipsFields(x, y, size, ori);
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {

			int k = 0;
			while (k < size && (ships[i].occupiedFields[j].x == shipsFields[k].x && ships[i].occupiedFields[j].y != shipsFields[k].y ||
				ships[i].occupiedFields[j].x != shipsFields[k].x && ships[i].occupiedFields[j].y == shipsFields[k].y ||
				ships[i].occupiedFields[j].x != shipsFields[k].x && ships[i].occupiedFields[j].y != shipsFields[k].y)) {
				k++;
			}

			if (k < size) {
				printf("!!! Invalid ship placement: Ship Collison !!!\n\n");
				return 1;
			}

		}
	}

	return 0;
}


void getShips(int numS, int dim, Player* player) {
	player->ships = (Ship*)malloc(sizeof(Ship) * numS);

	for (int i = 1; i <= numS; i++) {

		system("cls");

		Ship shipInstance;

		int x, y, orientation;

		renderMap(player->playerTable, dim);

		do {

			do {
				
				printf("PLACEING %d LONG SHIP\n", i);
				do {
					printf("\tOrientation of the ships (1: vertical | 2: horizontal): ");
					scanf_s("%d", &orientation);
				} while (orientation != 1 && orientation != 2);

				printf("\tX starting coordinate: ");
				scanf_s("%d", &x);
				printf("\tY starting coordinate: ");
				scanf_s("%d", &y);
				printf("\n");

				x -= 1;
				y -= 1;

			} while (willShipCollide(x, y, i, orientation, player->ships));


		} while (!isShipValid(x, y, orientation, i, dim));

		shipInstance.size = i;
		shipInstance.occupiedFields = getShipsFields(x, y, i, orientation);
		shipInstance.state = 1;
		player->ships[i - 1] = shipInstance;

		updatePlayerTable(player);
	}
}

void InitializePlayers(Player* player1, int dimension, int numOfShips) {
	player1->playerTable = AllocateCharMatrix(dimension, dimension);
	player1->hitMap = AllocateCharMatrix(dimension, dimension);

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			player1->playerTable[i][j] = '*';
			player1->hitMap[i][j] = '?';
		}
	}

	getShips(numOfShips, dimension, player1);
}
#endif