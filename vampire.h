#ifndef ___VAMPIRE_H___
#define ___VAMPIRE_H___
#include <string>
#include "player.h"

class Vampire: public Player {
	public:
	// Constructor
	Vampire();

	void heal(int amount);
	std::string attack(std::string dir);
};
#endif
