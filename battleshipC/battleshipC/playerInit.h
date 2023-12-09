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

int isShipValid(int x, int y, int ori, int size, int dim) {
	size -= 1;
	if (ori == 2) {
		if (y + size < dim && y > -1 && x < dim && x > -1) return 1;
	}
	else if (ori == 1) {
		if (y < dim && y > -1 && x - size > -1 && x < dim) return 1;
	}

	printf("\n\n!!! Invalid ship placement: Invalid Coordinates !!!\n\n");
	return 0;
}


Field getShipsFields(int offset, int starterX, int starterY, int orientation) {
	Field shipField;
	if (orientation == 1) {
		shipField.x = starterX - offset;
		shipField.y = starterY;
		shipField.state = 1;
	}
	else if (orientation == 2) {
		shipField.x = starterX;
		shipField.y = starterY + offset;
		shipField.state = 1;
	}

	return shipField;
}

int willShipCollide(int x, int y, int size, int ori, Ship* ships) {
	Field* shipsFields = (Field*)malloc(sizeof(Field) * size);

	for (int i = 0; i < size; i++) {
		shipsFields[i] = getShipsFields(i, x, y, ori);
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {

			int k = 0;
			while (k < size && (ships[i].occupiedFields[j].x == shipsFields[k].x && ships[i].occupiedFields[j].y != shipsFields[k].y ||
				ships[i].occupiedFields[j].x != shipsFields[k].x && ships[i].occupiedFields[j].y == shipsFields[k].y ||
				ships[i].occupiedFields[j].x != shipsFields[k].x && ships[i].occupiedFields[j].y != shipsFields[k].y)) {
				k++;
			}

			if (k < size) {
				printf("\n\n!!! Invalid ship placement: Ship Collison Iminent !!!\n\n");
				return 1;
			}

		}
	}

	return 0;
}


void getShips(int dim, Player* player) {
	player->ships = (Ship*)malloc(sizeof(Ship) * player->numberOfShips);
	for (int i = 1; i <= player->numberOfShips; i++) {
		system("cls");
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
				scanf("%d", &x);
				printf("\tY starting coordinate: ");
				scanf("%d", &y);

				x -= 1;
				y -= 1;

			} while (willShipCollide(x, y, i, orientation, player->ships));


		} while (!isShipValid(x, y, orientation, i, dim));

		player->ships[i - 1].occupiedFields = (Field*)malloc(sizeof(Field) * i);

		for (int j = 0; j < i; j++) {
			player->ships[i - 1].occupiedFields[j] = getShipsFields(j, x, y, orientation);
		}

		player->ships[i - 1].size = i;
		player->ships[i - 1].state = 1;

		updateIncompleteMap(player, i);
	}
}

void InitializePlayers(Player* player1, int dimension, int numberOfShips) {
	system("cls");
	printf("Player's Name: ");
	scanf("%s", player1->name);
	system("cls");

	player1->numberOfShips = numberOfShips;


	player1->playerTable = (char**)malloc(sizeof(char*) * dimension);
	for (int i = 0; i < dimension; i++) {
		player1->playerTable[i] = (char*)malloc(sizeof(char) * dimension);
	}

	player1->hitMap = (char**)malloc(sizeof(char*) * dimension);
	for (int i = 0; i < dimension; i++) {
		player1->hitMap[i] = (char*)malloc(sizeof(char) * dimension);
	}

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			player1->playerTable[i][j] = '*';
			player1->hitMap[i][j] = '*';
		}
	}

	getShips(dimension, player1);
}

#endif