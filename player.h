#ifndef ___PLAYER_H___
#define ___PLAYER_H___
#include "character.h"
#include <iostream>

class Player: public Character {
	protected:
	int moneyCoins;

        virtual bool attack(std::string dir);
        virtual bool move(std::string dir);
        virtual bool pickup(std::string dir);
        virtual bool use(std::string dir);

	public:
	Player(); // REMOVE THIS WHEN DONE
	Player(std::string race, int maxhp, int hp, int atk, int def);

	std::string performAction(std::string command, std::string dir);
	bool onDeath(Character *c);

	// Player Accessors
	virtual std::string getRace();
	virtual int gethp();
	virtual int getatk();
	virtual int getdef();
	virtual int getGold();
	virtual int getScore();

	virtual ~Player() = 0; // for making this pure virtual only
};
#endif
