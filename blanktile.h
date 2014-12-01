#ifndef ___BLANKTILE_H___
#define ___BLANKTILE_H___
#include <string>
#include "tile.h"

class Player;
class Enemy;

class BlankTile: public Tile {
	public:
	void addNeighbour(Tile *t);
	// Overrides for the isSteppedOn methods in Tile
	bool isSteppedOn(Player *p);
	bool isSteppedOn(Enemy *e);
};
#endif
