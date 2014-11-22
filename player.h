#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"

class Player: public Character {
	bool onDeath(Character *c);	
	
	protected:
	int moneyCoins;

	public:
	bool onDeath(Character *c);
	virtual int getScore();		
};
#endif
