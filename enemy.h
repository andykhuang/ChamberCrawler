#ifndef ___ENEMY_H___
#define ___ENEMY_H___
#include <string>
#include "character.h"

class Tile;
class Player;
class Treasure;

class Enemy: public Character {
	void onDeath(Character *c);

	protected:
	Treasure *eTreasure;

	std::string attack(std::string dir);
        bool move(std::string dir);
        std::string pickup(std::string dir);
        std::string use(std::string dir);

	public:
	// Constructor
	Enemy();	// TODO: REMOVE WHEN DONE
	Enemy(std::string race, int maxhp, int hp, int atk, int def);

	std::string performAction(std::string command="", std::string dir="");
	std::string isAttacked(Character *c);

	// Destructor
	virtual ~Enemy();
};
#endif
