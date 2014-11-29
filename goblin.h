#ifndef ___GOBLIN_H___
#define ___GOBLIN_H___
#include <string>
#include "player.h"

class Goblin: public Player {
	public:
	// Constructor
	Goblin();
	
	std::string isAttacked(Character *c);
};
#endif
