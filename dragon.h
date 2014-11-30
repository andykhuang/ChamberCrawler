#ifndef ___DRAGON_H___
#define ___DRAGON_H___
#include <string>
#include "enemy.h"

class DragonTreasure;

class Dragon: public Enemy {
	// The DragonTreasure that the dragon is guarding
	DragonTreasure *treasure;

	std::string onDeath(Character *c);

	std::string move(std::string dir);
	std::string attack();

	public:
	// Constructor
	Dragon(DragonTreasure *t);

	void setTile(Tile *t);
};
#endif
