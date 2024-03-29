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
	DragonTreasure(Tile *dHost, Tile *tHost);

	bool isPickedUp(Player *p);
	bool isPickedUp(Enemy *e);
	bool canBeSteppedOn(Player *p);
	bool canBeSteppedOn(Enemy *e);

	void dualSetHost(Tile *dHost, Tile *tHost);
	void setHost(Tile *t);

	// Called by the Dragon when it is slain to remove the dragon guarding
	// the treasure
	void clearDragon();

	// The Dragon is a friend of the DragonTreasure
	friend class Dragon;
};
#endif
