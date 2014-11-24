#ifndef ___HUMAN_H___
#define ___HUMAN_H___
#include "enemy.h"

class Human: public Enemy {
	public:
	// Constructor
	Human();
	
	bool onDeath(Character *c);
};
#endif
