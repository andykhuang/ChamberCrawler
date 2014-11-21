#ifndef ___TILE_H___
#define ___TILE_H___
#include <iostream>

class Character;
class Player;
class Item;

class Tile {
	protected:
	Tile *neighbours;

	Item *item;
	Character *character;
	char tileSymbol;

	public:
	// Constructors
	Tile();

	// Returns whether this Tile has something "on" it
	virtual bool isOccupied(Player *p);
	virtual bool isOccupied(Enemy *e);
	// Tries to place a Character on this Tile and return whether it succeeded
	virtual bool placeCharacter(Character *c);
	// Tries to place an Item on this Tile and return whether it succeeded
	virtual bool placeItem(Item *i);
	// Try to step on this Tile and return whether it succeeded
	virtual bool isSteppedOn(Player *p);
	virtual bool isSteppedOn(Enemy *e);

	// Destructor
	virtual ~Tile() = 0;

	friend std::ostream &operator<<(std::ostream &out, const Tile &t);
};
#endif
