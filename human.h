#ifndef ___HUMAN_H___
#define ___HUMAN_H___
#include "enemy.h"

class Human: public Enemy {
	void onDeath(Character *c);

	public:
	// Constructor
	Human();
};
#endif
