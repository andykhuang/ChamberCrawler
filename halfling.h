#ifndef ___HALFLING_H___
#define ___HALFLING_H___
#include "enemy.h"

class Halfling: public Enemy {
	public:
	// Constructor
	Halfling();
	
	bool isAttacked(Character *p);
};
#endif
