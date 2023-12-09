#ifndef GAMEROUND_H
#define GAMEROUND_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "dataStructures.h"
#include "utilityFunctions.h"

int isShipSunk(Ship* ship) {
	int i = 0;
	while (i < ship->size && ship->occupiedFields[i].state != 1) {
		i++;
	}

	if (i < ship->size) {
		return 1;
	}
	else return;
}

int didShotHit(Player* reciver, int x, int y) {
	int hit = 0;
	int i = 0;
	while (i < reciver->numberOfShips && hit == 0) {
		int j = 0;
		while (j < reciver->ships[i].size && hit == 0) {
			int shipX = reciver->ships[i].occupiedFields[i].x;
			int shipY = reciver->ships[i].occupiedFields[j].y;
			int state = reciver->ships[i].occupiedFields[j].state;
			if (shipX == x && shipY == y && state == 1) {
				reciver->ships[i].occupiedFields[j].state = 0;
				hit = 1;
			}
		}
	}

	if (hit == 1) {
		if (isShipSunk(&reciver->ships[i - 1])) {
			return 2;
		}
		else return 1;
	}
	else return 0;
}

void fire(Player* attacker, Player* reciver, int dim) {
	renderMap(attacker->playerTable, dim);
	renderMap(attacker->hitMap, dim);
	printf("Ships long range cannons fireing at given coordinates:");

	int x, y;
	do
	{
		printf("\tCoordinate X: ");
		scanf_s("%d", &x);
		printf("\tCoordinate Y: ");
		scanf_s("%d", &y);

		if (x > dim - 1 && x < -1 && y > dim - 1 && y < -1) printf("\n!! Invalid Coordinates !!\n");
	} while (x > dim - 1 && x < -1 && y > dim - 1 && y < -1);

	if (didShotHit(reciver, x, y) != 0) {
		attacker->hitMap[x][y] = 'X';
		fire(attacker, reciver, dim);
	}
	else {
		attacker->hitMap[x][y] = 'O';
	}
}

void gameRound(Player* attackPlayer, Player* enemy, int dim) {
	fire(attackPlayer, enemy, dim);
	updatePlayerTable(attackPlayer);
	updatePlayerTable(enemy);
}

#endif
