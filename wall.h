#ifndef ___WALL_H___
#define ___WALL_H___
#include <string>
#include "tile.h"

class Player;
class Enemy;

class Wall: public Tile {
	public:
	// Constructor
	Wall(bool isVertical);

	void addNeighbour(Tile *t);

	// Overrides for the isSteppedOn methods in Tile
	bool isSteppedOn(Player *p);
	bool isSteppedOn(Enemy *e);
};
#endif
