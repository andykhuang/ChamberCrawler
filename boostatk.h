#ifndef ___BOOSTATK_H___
#define ___BOOSTATK_H___
#include "potion.h"

class Player;
class Enemy;

class BoostAtk:public Potion {
	// Determines whether the Potion is mysterious to the Player
	static bool hasEncountered;

	public:
	// Constructor
	BoostAtk(AbstractPotion *p);

	int getAtk();

	bool isUsed(Player *p);
};
#endif
