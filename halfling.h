#ifndef ___HALFLING_H___
#define ___HALFLING_H___
#include <string>
#include "enemy.h"

class Halfling: public Enemy {
	public:
	// Constructor
	Halfling();
	
	std::string isAttacked(Character *p);
};
#endif
