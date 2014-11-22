#ifndef ___GOBLIN_H___
#define ___GOBLIN_H___
#include "player.h"

class Goblin: public Player {
	public:
	// Constructor
	Goblin();
	
	bool isAttacked(Character *c);
};
#endif
