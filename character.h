#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___
#include <string>
#include <iostream>

class Tile;
class AbstractPotion;

class Character {
	virtual std::string attack(std::string dir) = 0;
	virtual bool move(std::string dir) = 0;
	virtual std::string pickup(std::string dir) = 0;
	virtual std::string use(std::string dir) = 0;
 
	virtual bool onDeath(Character *c) = 0;

	protected:
	Tile *host;
	char characterSymbol;
	std::string race;

	int maxhp, hp, atk, def;
	AbstractPotion *pot;

	public:
	// Constructor
	Character();
	Character(std::string race, int maxhp, int hp, int atk, int def);
	
	virtual void setTile(Tile *t);
	virtual std::string performAction(std::string command, std::string dir) = 0;
	virtual std::string isAttacked(Character *c) = 0;

	// Increments the Character's HP by the amount specified
	// If the amount is negative, decrement the Character's HP instead
	virtual void heal(int amount);
	virtual bool isDead();

	// Accessors
	virtual std::string getRace();
	virtual int gethp();
	virtual int getatk();
	virtual int getdef();

	// Destructor
	virtual ~Character();

	friend std::ostream &operator<<(std::ostream &out, const Character &c);
};
#endif
