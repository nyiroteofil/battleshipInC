#define _CRT_SECURE_NO_WARNINGS

typedef struct Player Player;
typedef struct Ship Ship;
typedef struct Field Field;
typedef struct Settings Settings;

#include "playerInit.h"
#include "dataStructures.H"
#include "utilityFunctions.h"
#include "gameRound.h"

int main() {

	Settings GameSettings;

	do {
		// initializing the games settings with the dimensions of the playing field and the max size 
		// of ships (this number meands the number of ships too, as one ship of all the sizes) 
		printf("Playing field size(N x N): ");
		scanf_s("%d", &GameSettings.dimensions);
		printf("Max size of the ships: ");
		scanf_s("%d", &GameSettings.maxNumberOfShips);
		system("cls");
	} while (GameSettings.dimensions < 5 || GameSettings.dimensions > 15 || GameSettings.maxNumberOfShips > (int)((double)GameSettings.dimensions * 0.7));
	// Initializing the two players and their ships 
	Player players[2];
	Player player1, player2;
	InitializePlayers(&player1, GameSettings.dimensions, GameSettings.maxNumberOfShips);
	InitializePlayers(&player2, GameSettings.dimensions, GameSettings.maxNumberOfShips);
	players[0] = player1;
	players[1] = player2;
	// the game round repeats until one of the player runs out of ships 
	// the isGameOver(player) chechs if the player left any active ships (not shunk)
	int gameState = 1;
	do {
		gameRound(&players[0], &players[1], GameSettings.dimensions);

		if (isGameOver(&players[1]) || isGameOver(&players[1])) {
			gameState = 0;
		}
		else {
			switchPlayers(players);
		}
	} while (gameState);


	printf("%s WON!!!", players[0].name);
	Sleep(10000);

	//freeing the allocated memory
	freeCharMatrix(players[0].hitMap, GameSettings.dimensions, GameSettings.dimensions);
	freeCharMatrix(players[0].playerTable, GameSettings.dimensions, GameSettings.dimensions);
	freeCharMatrix(players[1].hitMap, GameSettings.dimensions, GameSettings.dimensions);
	freeCharMatrix(players[1].playerTable, GameSettings.dimensions, GameSettings.dimensions);
	for (int i = 0; i < GameSettings.maxNumberOfShips; i++) {
		free(players[0].ships[i].occupiedFields);
		free(players[1].ships[i].occupiedFields);
	}
	free(players[0].ships);
	free(players[1].ships);

	return 0;
}