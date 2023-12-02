#include <stdio.h>
#include <string.h>
#include <math.h>

#include "dataStructs.c"

struct Player InitializePlayer(int numP, /*n-th player*/int numD /*dimensions of the playing field*/, int numS /*length of the largest ship*/) {

	struct Player playerInstance;
	playerInstance.playerTable = (char**)malloc(sizeof(char) * (numD * numD));

	for (int i = 0; i < numD; i++) {
		for (int j = 0; j < numD; j++) {
			strcpy(playerInstance.playerTable[i][j], "#");
		}
	}


	playerInstance.ships = (struct Ship*)malloc(sizeof(struct Ship) * numP); //allocating memory for the ships
	
	for (int i = numS; i > 0; i--) {
		struct Ship shipInstance;

		int shipCollison = 0;
		do
		{
			shipInstance.occupiedFields = getShipFields(numD, i);

			for (int si = 0; si < abs(i - numS); si++) {		// si = ship index
				for (int fi = 0; fi < playerInstance.ships[si].size; fi++) {
					for (int nf = 0; nf < i; nf++) {
						int usedX = playerInstance.ships[si].occupiedFields[fi].x;
						int usedY = playerInstance.ships[si].occupiedFields[fi].y;
						int newX = shipInstance.occupiedFields[nf].x;
						int newY = shipInstance.occupiedFields[nf].y;
						
						if (usedX == newX && usedY == newY) shipCollison = 1;
					}
				}
			}

		} while (shipCollison != 0);

		playerInstance.ships[abs(i - numS)] = shipInstance;
	}


}


struct Field* getShipFields( int numD, int shipSize) {

	struct Field* fields = (struct Field*)malloc(sizeof(struct Field) * shipSize);

	printf("Placing %d long ship:\n", shipSize);
	int x, y;
	int orientation;
	int collison = 0;

	do
	{
		do
		{
			printf("\tShip's orientation (1: vertical | 2: horizontal): ");
			scanf_s("\t%d", &orientation);
		} while (orientation != 1 && orientation != 2);

		printf("\tStarting coordinate X: ");
		scanf_s("%d", &x);
		printf("\tStarting coordinate Y: ");
		scanf_s("%d", &y);

	} while (orientation != 2 || x + 8 > numD || x < 0 || y > numD || y < 0 &&
		orientation != 1 || y + 8 > numD || y < 0 || x > numD || x < 0 && collison == 1);

	if (orientation == 1) {
		for (int i = 0; i < shipSize; i++) {
			struct Field fieldInstance;
			fieldInstance.x = x;
			fieldInstance.y = y + i;
			fields[i] = fieldInstance;
		}
	}
	else {
		for (int i = 0; i < shipSize; i++) {
			struct Field fieldInstance;
			fieldInstance.x = x + i;
			fieldInstance.y = y;
			fields[i] = fieldInstance;
		}
	}
	


	return fields;
}