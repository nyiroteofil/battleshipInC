#define _CRT_SECURE_NO_WARNINGS

typedef struct Player Player;
typedef struct Ship Ship;
typedef struct Field Field;

#include "playerInit.h""
#include "dataStructures.H"
#include "utilityFunctions.h"
#include "gameRound.h"

int main() {

	int numberOfShips, gameDimensions;

	do {
		printf("Playing field size(N x N): ");
		scanf_s("%d", &gameDimensions);
		printf("Max size of the ships: ");
		scanf_s("%d", &numberOfShips);
		system("cls");
	} while (gameDimensions > 99 || gameDimensions > 15 || numberOfShips > (int)((double)gameDimensions * 0.7));

	Player players[2];
	Player player1, player2;
	InitializePlayers(&player1, gameDimensions, numberOfShips);
	InitializePlayers(&player2, gameDimensions, numberOfShips);
	players[0] = player1;
	players[1] = player2;

	int gameState = 1;
	do {
		gameRound(&players[0], &players[1], gameDimensions);

		if (isGameOver(&players[1]) || isGameOver(&players[1])) {
			gameState = 0;
		}
		else {
			switchPlayers(players);
		}
	} while (gameState);


	printf("%s WON!!!", players[0].name);

	//freeing the allocated memory
	freeCharMatrix(players[0].hitMap, gameDimensions, gameDimensions);
	freeCharMatrix(players[0].playerTable, gameDimensions, gameDimensions);
	freeCharMatrix(players[1].hitMap, gameDimensions, gameDimensions);
	freeCharMatrix(players[1].playerTable, gameDimensions, gameDimensions);
	for (int i = 0; i < numberOfShips; i++) {
		free(players[0].ships[i].occupiedFields);
		free(players[1].ships[i].occupiedFields);
	}
	free(players[0].ships);
	free(players[1].ships);

	return 0;
}