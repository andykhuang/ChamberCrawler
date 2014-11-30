#ifndef ___TROLL_H___
#define ___TROLL_H___
#include <string>
#include "player.h"

class Troll: public Player {
	std::string hiddenPower();	

	public:
	// Constructor
	Troll();
};
#endif
