#ifndef ___TILE_H___
#define ___TILE_H___

class Character;
class Player;
class Item;

class Tile {
	Item *item;
	Character *character;

	public:
	// Constructors
	Tile();
	Tile(Character *c);
	Tile(Item *i);
	// Returns whether this Tile has something "on" it
	virtual bool isOccupied();
	// Tries to place a Character on this Tile and return whether it succeeded
	virtual bool placeCharacter(Character *c);
	// Tries to place an Item on this Tile and return whether it succeeded
	virtual bool placeItem(Item *i);
	// Try to step on this Tile and return whether it succeeded
	virtual bool isSteppedOn(Player *p);
	virtual bool isSteppedOn(Enemy *e);
};
#endif
