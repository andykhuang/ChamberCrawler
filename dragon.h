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
	Dragon(DragonTreasure *dt);
	
	void setTile(Tile *t);
	
	bool attack(std::string dir);
};
#endif
