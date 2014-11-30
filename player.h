#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include <string>
#include <iostream>
#include "character.h"

class Potion;

class Player: public Character {
	protected:
	int moneyCoins;

        std::string attack(std::string dir);
        std::string move(std::string dir);
        std::string pickup(std::string dir);
        std::string use(std::string dir);

	public:
	Player(); // REMOVE THIS WHEN DONE
	Player(std::string race, int maxhp, int hp, int atk, int def);

	std::string performAction(std::string command = "", std::string dir = "");
	std::string isAttacked(Character *c);
	bool onDeath(Character *c);

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

	virtual ~Player() = 0; // for making this pure virtual only
};
#endif
