#ifndef ___HUMAN_H___
#define ___HUMAN_H___
#include <string>
#include "enemy.h"

class Human: public Enemy {
	std::string onDeath(Character *c);

	public:
	// Constructor
	Human();
};
#endif
