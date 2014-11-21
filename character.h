#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___
#include <string>

class Tile;
class Potion;

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
	Potion *pot;

	public:
	// Constructor
	Character();

	virtual std::string performAction(std::string command, std::string dir);
	virtual bool isAttacked(Character *c) = 0;
	virtual bool isDead();

	// Destructor
	virtual ~Character();
};
#endif
