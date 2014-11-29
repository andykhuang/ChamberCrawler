#ifndef ___DRAGONTREASURE_H___
#define ___DRAGONTREASURE_H___
#include "treasure.h"

class Dragon;
class Player;
class Enemy;

class DragonTreasure: public Treasure {
	Dragon *d;

	public:
	// Constructor
	DragonTreasure();

	bool isPickedUp(Player *p);
	bool isPickedUp(Enemy *e);
	bool canBeSteppedOn(Player *p);
	bool canBeSteppedOn(Enemy *e);

	void setHost(Tile *t);

	// Called by the Dragon when it is slain to remove the dragon guarding
	// the treasure
	void clearDragon();
};
#endif
