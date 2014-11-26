#ifndef ___ENEMY_H___
#define ___ENEMY_H___
#include <string>
#include "character.h"

class Treasure;

class Enemy: public Character {
	bool onDeath(Character *c);

	protected:
	Treasure *t;

	public:
	std::string performAction(std::string command, std::string dir);

	// Constructor
	Enemy();
	// Destructor
	virtual ~Enemy();
};
#endif
