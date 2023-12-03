#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Player Player;
typedef struct Ship Ship;
typedef struct Field Field;

#include "battleshipFunctions.h"
#include "dataStructures.H"

int main() {

	Player player1, player2;
	InitializePlayers(&player1, 8, 5);

	return 0;
}