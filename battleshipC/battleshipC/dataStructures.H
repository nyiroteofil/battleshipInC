#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

struct Field {
	int x;
	int y;
	int state; //active or inactive (1 / 0)
};

struct Ship {
	int size;
	struct Field* occupiedFields;
	int state; //if state == 0 the ship has been sunk, if it's 1 it's still operational
};

struct Player {
	struct Ship* ships;
	char** playerTable;
};

#endif