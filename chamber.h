#ifndef ___CHAMBER_H___
#define ___CHAMBER_H___
#include <string>

class Tile;

class Chamber {
	// Private fields
	Tile **tiles;
	int size;

	public:
	Chamber(Tile **tiles, int size);

	// Place an entity with the given name on a random tile
	void place(std::string name);
	~Chamber();
};
#endif
