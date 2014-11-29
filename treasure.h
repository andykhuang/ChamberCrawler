#ifndef ___TREASURE_H___
#define ___TREASURE_H___
#include "item.h"

class Player;
class Enemy;

class Treasure: public Item {
	protected:
	int value;

	public:
	// Constructor
	Treasure(int value);
	
	// Tries to step on this treasure
	bool canBeSteppedOn(Player *p);
	bool canBeSteppedOn(Enemy *e);
	
	// Called when the Teasure is picked up. Returns True if successfully picked
	bool isPickedUp(Player *p);
	bool isPickedUp(Enemy *e);
};
#endif
