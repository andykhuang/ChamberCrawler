#ifndef ___ITEM_H___
#define ___ITEM_H___
#include <iostream>
#include <string>

class Tile;
class Player;
class Enemy;

class Item {
	protected:
	Tile *host;

	char itemSymbol;
	std::string name;
	std::string desc;

	public:
	// Constructor
	Item();

	// Set the host field for this Item
	// This method is overloaded by the DragonTreasure subclass
	void setHost(Tile *t);
	// Can you step on this item?
	virtual bool canBeSteppedOn(Player *p) = 0;
	virtual bool canBeSteppedOn(Enemy *e) = 0; 
	// Tries to pick up 
	virtual bool isPickedUp(Player *p) = 0;
	virtual bool isPickedUp(Enemy *e) = 0;
	virtual bool isUsed(Player *e);
	virtual bool isUsed(Enemy *e);

	virtual std::string getName();	

	// Destructor
	virtual ~Item() = 0;

	friend std::ostream &operator<<(std::ostream &out, const Item &i);
};
#endif
