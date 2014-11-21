#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"

class Player: public Character {
	bool onDeath(Character *c);	

	public:
	void move(int dir);
	bool isDead();
	void use(int dir);
	void pickup(int dir);
};
#endif
