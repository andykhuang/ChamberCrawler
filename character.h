#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___
#include <string>
#include <iostream>

class Tile;
class AbstractPotion;

class Character {
	virtual bool attack(std::string dir);
	virtual bool move(std::string dir);
	virtual bool pickup(std::string dir);
	virtual bool use(std::string dir);
 
	virtual bool onDeath(Character *c) = 0;

	protected:
	Tile *t;
	char characterSymbol;
	std::string race;

	int maxhp, hp, atk, def;
	AbstractPotion *pot;

	public:
	// Constructor
	Character();
	Character(std::string race, int maxhp, int hp, int atk, int def);

	virtual std::string performAction(std::string command, std::string dir);
	virtual bool isAttacked(Character *c);
	virtual bool isDead();

	// Destructor
	virtual ~Character();

	friend std::ostream &operator<<(std::ostream &out, const Character &c);
};
#endif
