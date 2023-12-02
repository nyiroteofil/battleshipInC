#include <stdio.h>
#include <string.h>
#include <math.h>

#include "dataStructs.c"

struct Player InitializePlayer(int numP, /*n-th player*/int numD /*dimensions of the playing field*/, int numS /*dimensions of ships*/) {

	struct Player playerInstance;
	playerInstance.playerTable = (char**)malloc(sizeof(char) * (numD * numD));

	for (int i = 0; i < numD; i++) {
		for (int j = 0; j < numD; j++) {
			strcpy(playerInstance.playerTable[i][j], "#");
		}
	}


	struct Ship* ships = (struct Ship*)malloc(sizeof(struct Ship) * numP); //allocating memory for the ships
	
	


	

}

struct Field* getShipFields( int numD, int shipSize) {

	struct Field* fields = (struct Field*)malloc(sizeof(struct Field) * shipSize);

	for (int i = 0; i > shipSize; i++) {
		struct Field fieldInstance;
		int orientation;

		do
		{
			do
			{
				printf("Ship's orientation (1: vertical | 2: horizontal): ");
				scanf_s("%d", &orientation);
			} while (orientation != 1 && orientation != 2);

			printf("Coordinate X: ");
			scanf_s("%d", &fieldInstance.x);
			printf("Coordinate Y: ");
			scanf_s("%d", &fieldInstance.y);

			fieldInstance.x -= 1;
			fieldInstance.y -= 1;
			fieldInstance.state = 1;

		} while (orientation != 2 || fieldInstance.x + 8 > numD || fieldInstance.x < 0 || fieldInstance.y > numD || fieldInstance.y < 0 &&
				 orientation != 1 || fieldInstance.y + 8 > numD || fieldInstance.y < 0 || fieldInstance.x > numD || fieldInstance.x < 0);
		
		fields[i] = fieldInstance;
	}

}