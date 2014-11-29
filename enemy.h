#ifndef ___ENEMY_H___
#define ___ENEMY_H___
#include <string>
#include "character.h"

class Tile;
class Treasure;

class Enemy: public Character {
	bool onDeath(Character *c);

	protected:
	Treasure *eTreasure;

	virtual bool attack(std::string dir);
        virtual bool move(std::string dir);
        virtual bool pickup(std::string dir);
        virtual bool use(std::string dir);

	public:
	std::string performAction(std::string command="", std::string dir="");

	// Constructor
	Enemy();	// REMOVE WHEN DONE
	Enemy(std::string race, int maxhp, int hp, int atk, int def);
	// Destructor
	virtual ~Enemy();
};
#endif
