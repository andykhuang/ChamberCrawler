#ifndef ___STAIRS_H___
#define ___STAIRS_H___
#include "floortile.h"
#include "game.h"

class Stairs: public FloorTile {
	Game *g;

	public:
	// Constructor
	Stairs(Game *g);	

	bool isSteppedOn(Player *p);
	bool isOccupied(Player *p);
	bool isOccupied(Enemy *e);
};
#endif
