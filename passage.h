#ifndef ___PASSAGE_H___
#define ___PASSAGE_H___
#include "tile.h"

class Enemy;
class Player;

class Passage: public Tile {
	public:
	// Constructor
	Passage();

	bool isSteppedOn(Player *p);
	bool isSteppedOn(Enemy *e);
};
#endif
