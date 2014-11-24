#ifndef ___CHAMBER_H___
#define ___CHAMBER_H___
#include <string>

class Tile;
class Character;
class Item;
class Stairs;

class Chamber {
	// Private fields
	Tile **tiles;
	int size;

	public:
	Chamber(Tile **tiles, int size);

	// Place an entity on a random tile in this chamber
	bool place(Character *c);
	bool place(Item *i);
	bool place(Stairs *s);
	~Chamber();
};
#endif
