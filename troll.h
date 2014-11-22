#ifndef ___TROLL_H___
#define ___TROLL_H___
#include <string>
#include "player.h"

class Troll: public Player {
	public:
	// Constructor
	Troll();

	std::string performAction(std::string command, std::string dir);
};
#endif
