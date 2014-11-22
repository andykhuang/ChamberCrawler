#ifndef ___DRAGON_H___
#define ___DRAGON_H___
#include <string>
#include "enemy.h"

class DragonTreasure;

class Dragon: public Enemy {
	// The DragonTreasure that the dragon is guarding
	DragonTreasure *treasure;

	public:
	// Constructor
	Dragon();
	
	bool Attack(std::string dir);
};
#endif
