#ifndef ___POISONHEALTH_H___
#define ___POISONHEALTH_H___
#include "potion.h"

class Player;
class Enemy;

class PoisonHealth:public Potion {
	// Determines whether the Potion is mysterious to the Player
	static bool hasEncountered;

	public:
	// Constructor
	PoisonHealth(AbstractPotion *p);

	bool isUsed(Player *p);
	bool isUsed(Enemy *e);
};
#endif
