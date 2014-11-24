#ifndef ___VAMPIRE_H___
#define ___VAMPIRE_H___
#include <string>
#include "player.h"

class Vampire: public Player {
	public:
	// Constructor
	Vampire();

	bool attack(std::string dir);
};
#endif
