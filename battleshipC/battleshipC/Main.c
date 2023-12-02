#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "battleshipFunctions.c"
#include "dataStructs.c"

int main() {
	struct Player playerInstance;
	InitializePlayer(8, 5, &playerInstance);
	uptdatePlayerTable(&playerInstance, 5);
	RenderPlayerTable(&playerInstance, 8);

	return 0;
}