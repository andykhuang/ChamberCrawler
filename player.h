#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include <string>
#include <iostream>
#include "character.h"

class Potion;

class Player: public Character {
	std::string onDeath(Character *c);
	virtual std::string hiddenPower();

	protected:
	int moneyCoins;

	virtual std::string attack(std::string dir);
	virtual std::string move(std::string dir);
	virtual std::string pickup(std::string dir);
	virtual std::string use(std::string dir);

	public:
	Player(std::string race, int maxhp, int hp, int atk, int def);

	std::string performAction(std::string command = "", std::string dir = "");
	std::string isAttacked(Character *c);
	
	// Called at the end of every Floor to remove the Potion(s) this Player has
	void flushPot();

	// Increments the Player's moneyCoins by the amount specified
	// If the amount is negative, decrement the Player's moneyCoins instead
	virtual void bank(int amount);

	// Player Accessors
	int getatk();
	int getdef();
	virtual int getGold();
	virtual int getScore();

	bool isPlayer();

	static std::string convertDirection(std::string dir);
	
	AbstractPotion *getPotion();

	// Player Mutators
	virtual void setPotion(AbstractPotion *p);

	// Destructor
	virtual ~Player() = 0; // for making this pure virtual only
};
#endif
