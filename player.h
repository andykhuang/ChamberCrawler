#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"

class Player: public Character {
	protected:
	int moneyCoins;

	public:
	Player(); // REMOVE THIS WHEN DONE
	Player(std::string race, int maxhp, int hp, int atk, int def);
	bool onDeath(Character *c);
	virtual int getScore();
	~Player() = 0; // for making this pure virtual only
};
#endif
