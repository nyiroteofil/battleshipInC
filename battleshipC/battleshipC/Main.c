#define _CRT_SECURE_NO_WARNINGS

typedef struct Player Player;
typedef struct Ship Ship;
typedef struct Field Field;

#include "playerInit.h"
#include "dataStructures.H"
#include "utilityFunctions.h"

int main() {

	Player player1, player2;
	InitializePlayers(&player1, 10, 5);
	InitializePlayers(&player2, 10, 5);

	return 0;
}