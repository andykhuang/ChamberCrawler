#ifndef ___BLANKTILE_H___
#define ___BLANKTILE_H___
#include <string>
#include "tile.h"

class Player;
class Enemy;

class BlankTile: public Tile {
	public:
	void addNeighbour(Tile *t);
	// Overrides for the isOccupied methods in Tile
	bool isOccupied(Player *p);
	bool isOccupied(Enemy *e);
	// Overrides for the isSteppedOn methods in Tile
	bool isSteppedOn(Player *p);
	bool isSteppedOn(Enemy *e);
	// Overrides for the isAttacked methods in Tile
	std::string isAttacked(Player *p);
	std::string isAttacked(Enemy *e);
};
#endif
