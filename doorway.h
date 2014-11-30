#ifndef ___DOORWAY_H___
#define ___DOORWAY_H___
#include "tile.h"

class Player;

class Doorway: public Tile {
	public:
	// Constructor
	Doorway();

	bool isSteppedOn(Player *p);
	bool isSteppedOn(Enemy *e);
};
#endif
