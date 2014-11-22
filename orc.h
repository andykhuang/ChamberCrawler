#ifndef ___ORC_H___
#define ___ORC_H___
#include <string>
#include "enemy.h"

class Orc: public Enemy {
	public:
	// Constructor
	Orc();
	
	bool attack(std::string dir);	
};
#endif
