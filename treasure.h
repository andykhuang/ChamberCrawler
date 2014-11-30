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
	bool isPickedUp(Player *p);
	bool isPickedUp(Enemy *e);

	int getValue();
};
#endif
