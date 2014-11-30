#ifndef ___RESTOREHEALTH_H___
#define ___RESTOREHEALTH_H___
#include "potion.h"

class Player;
class Enemy;

class RestoreHealth:public Potion {
	// Determines whether the Potion is mysterious to the Player
	static bool hasEncountered;

	public:
	// Constructor
	RestoreHealth(AbstractPotion *p);
	
	bool isUsed(Player *p);
	bool isUsed(Enemy *e);

	std::string seesPotion();
};
#endif
