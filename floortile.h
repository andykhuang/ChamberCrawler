#ifndef ___FLOORTILE_H___
#define ___FLOORTILE_H___
#include "tile.h"

class Character;

class FloorTile: public Tile {
	public:
	// Constructors
	FloorTile();

	// Methods for handling Attacking, Using, and Picking up a Tile
	// std::string isAttacked(Player *p);	// Moved to superclass
	// std::string isAttacked(Enemy *e);	// Moved to superclass
	virtual bool isUsed(Character *c);
	virtual bool isPickedUp(Character *c);
	
	// Notifies the Character that's on it to perform an action
	virtual bool performAction();

	// Removes the Item or Character that's on the Tile
	void clearTile();
};
#endif
