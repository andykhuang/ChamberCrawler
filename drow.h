#ifndef ___DROW_H___
#define ___DROW_H___
#include <string>
#include "player.h"

class Drow: public Player {
	// Private methods
	bool use(std::string dir);
	
	public:
	// Constructor
	Drow();
};
#endif
