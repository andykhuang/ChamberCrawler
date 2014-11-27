#ifndef ___STAIRS_H___
#define ___STAIRS_H___
#include "floortile.h"
#include "item.h"
#include "game.h"

class Stairs: public Item {
	Game *g;

	public:
	// Constructor
	Stairs(Game *g);
	
	bool isPickedUp(Player *p);
	bool isPickedUp(Enemy *e);
	bool canBeSteppedOn(Player *p);
	bool canBeSteppedOn(Enemy *e);
	/*bool isSteppedOn(Player *p);
	bool isOccupied();
	bool isOccupied(Player *p);
	bool isOccupied(Enemy *e);
	*/
};
#endif
