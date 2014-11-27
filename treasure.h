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
	virtual bool canBeSteppedOn(Player *p);
	virtual bool canBeSteppedOn(Enemy *e);
	
	// Called when the Teasure is picked up. Returns True if successfully picked
	virtual bool isPickedUp(Player *p);
	virtual bool isPickedUp(Enemy *e);
};
#endif
