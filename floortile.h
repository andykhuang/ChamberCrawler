#ifndef ___FLOORTILE_H___
#define ___FLOORTILE_H___
#include <string>
#include "tile.h"

class Character;

class FloorTile: public Tile {
	public:
	// Constructors
	FloorTile();

	// Methods for handling Attacking, Using, and Picking up a Tile
	std::string isAttacked(Player *p);
	std::string isAttacked(Enemy *e);
	std::string isUsed(Player *c);
	std::string isPickedUp(Player *c);
	
	// Notifies the Character that's on it to perform an action
	virtual bool performAction();
};
#endif
