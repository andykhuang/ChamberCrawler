#ifndef ___DOORWAY_H___
#define ___DOORWAY_H___
#include "tile.h"

class Player;

class Doorway: public Tile {
	public:
	// Constructor
	Doorway();

	// Override the isOccupied method for Enemies to always return false
	bool isOccupied(Enemy *c);
};
#endif
