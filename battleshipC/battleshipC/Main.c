#define _CRT_SECURE_NO_WARNINGS

typedef struct Player Player;
typedef struct Ship Ship;
typedef struct Field Field;

#include "playerInit.h"
#include "dataStructures.H"
#include "utilityFunctions.h"
#include "gameRound.h"

int main() {

	int numberOfShips, gameDimensions;

	do {
		printf("Playing field size (N x N): ");
		scanf_s("%d", &gameDimensions);
		printf("Max size of the ships: ");
		scanf_s("%d", &gameDimensions);
		system("clr");
	} while (gameDimensions < 5 || gameDimensions > 99 || numberOfShips > (int)((float)gameDimensions * (5/3)));

	Player players[2];
	Player player1, player2;
	InitializePlayers(&player1, gameDimensions, numberOfShips);
	InitializePlayers(&player2, gameDimensions, numberOfShips);
	players[0] = player1;
	players[1] = player2;
	
	do {
		gameRound(&players[0], &players[1], gameDimensions);
		switchPlayers(players);
	} while (); // vége függvény megírása

	return 0;
}