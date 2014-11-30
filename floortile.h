#ifndef ___FLOORTILE_H___
#define ___FLOORTILE_H___
#include <string>
#include "tile.h"

class Character;

class FloorTile: public Tile {
	public:
	// Constructors
	FloorTile();

	bool isOccupied();

	// Methods for handling Attacking, Using, and Picking up a Tile
	std::string isAttacked(Player *p);
	std::string isAttacked(Enemy *e);
	std::string isUsed(Player *p);
	std::string isPickedUp(Player *p);
};
#endif
