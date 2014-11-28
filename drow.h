#ifndef ___DROW_H___
#define ___DROW_H___
#include <string>
#include "player.h"

class Drow: public Player {
	// Private methods
	// No longer need to have custom implementation for this in Drow
	// bool use(std::string dir);
	
	public:
	// Constructor
	Drow();

	void heal(int amount);
};
#endif
