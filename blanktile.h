#ifndef ___BLANKTILE_H___
#define ___BLANKTILE_H___
#include "tile.h"

class Player;
class Enemy;

class BlankTile: public Tile {
	void addNeighbour(Tile *t);
	bool isOccupied(Player *p);
	bool isOccupied(Enemy *e);
	bool isSteppedOn(Player *p);
	bool isSteppedOn(Enemy *e);
};
#endif
