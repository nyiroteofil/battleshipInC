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
		return 0;
	}
	else {
		ship->state = 0;
		return 1;
	}
}

int didShotHit(Player* reciver, int x, int y) {
	int hit = 0;
	int i = 0;
	while (i < reciver->numberOfShips && hit != 1) {
		int j = 0;
		while (j < reciver->ships[i].size && hit != 1) {
			int shipX = reciver->ships[i].occupiedFields[j].x;
			int shipY = reciver->ships[i].occupiedFields[j].y;
			int state = reciver->ships[i].occupiedFields[j].state;
			if (shipX == x && shipY == y && state == 1) {
				reciver->ships[i].occupiedFields[j].state = 0;
				hit = 1;
			}
			j++;
		}
		i++;
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
	system("cls");
	Sleep(2500);
	printf("Player: %s\n", attacker->name);
	renderMap(attacker->playerTable, dim);
	renderMap(attacker->hitMap, dim);
	printf("Ships long range cannons fireing at given coordinates: \n");

	int x, y;
	do
	{
		printf("\tCoordinate X: ");
		scanf_s("%d", &x);
		printf("\tCoordinate Y: ");
		scanf_s("%d", &y);

		x -= 1;
		y -= 1;

		if (x > dim - 1 && x < -1 && y > dim - 1 && y < -1) printf("\n!! Invalid Coordinates !!\n");
	} while (x >= dim || x < -1 || y >= dim || y < -1);

	int shipState = didShotHit(reciver, x, y);
	if (shipState != 0) {
		attacker->hitMap[x][y] = 'X';

		printf("Enemy ship hit!\n");
		if (shipState == 3) {
			printf("Ship have been sunk!\n");
		}

		fire(attacker, reciver, dim);
	}
	else {
		attacker->hitMap[x][y] = 'O';
		printf("shot missed!\n");
		Sleep(5000);
	}
}

void gameRound(Player* attackPlayer, Player* enemy, int dim) {
	fire(attackPlayer, enemy, dim);
	updatePlayerTable(attackPlayer);
	updatePlayerTable(enemy);
}

#endif