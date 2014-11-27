#ifndef ___WALL_H___
#define ___WALL_H___
#include "tile.h"

class Player;
class Enemy;

class Wall: public Tile {
	public:
	// Constructor
	Wall(bool isVertical);

	void addNeighbour(Tile *t);

	// Overrides for the isOccupied methods
	bool isOccupied(Player *p);
	bool isOccupied(Enemy *e);
	bool isSteppedOn(Player *p);
	bool isSteppedOn(Enemy *e);
};
#endif
