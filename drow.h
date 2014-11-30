#ifndef ___DROW_H___
#define ___DROW_H___
#include <string>
#include "player.h"

class Drow: public Player {
	public:
	// Constructor
	Drow();

	int getAtk();
	int getDef();

	void heal(int amount);
	std::string isAttacked(Character *c);
};
#endif
