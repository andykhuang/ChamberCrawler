#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"
#include <iostream>

class AbstractPotion;

class Player: public Character {
	protected:
	int moneyCoins;

	public:
	Player(); // REMOVE THIS WHEN DONE
	Player(std::string race, int maxhp, int hp, int atk, int def);

	bool onDeath(Character *c);

	// Increments the Player's HP by the amount specified
	// If the amount is negative, decrement the Player's HP instead
	virtual void heal(int amount);

	// Increments the Player's moneyCoins by the amount specified
	// If the amount is negative, decrement the Player's moneyCoins instead
	virtual void bank(int amount);

	// Player Accessors
	virtual std::string getRace();
	virtual int gethp();
	virtual int getatk();
	virtual int getdef();
	virtual int getGold();
	virtual int getScore();
	virtual AbstractPotion *getPotion();

	// Player Mutators
	virtual void setPotion(AbstractPotion *p);

	virtual ~Player() = 0; // for making this pure virtual only
};
#endif
