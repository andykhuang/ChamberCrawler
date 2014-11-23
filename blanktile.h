#ifndef ___BLANKTILE_H___
#define ___BLANKTILE_H___
#include "tile.h"

class Player;
class Enemy;

class BlankTile: public Tile {
	
	bool isOccupied(Player *p);
	bool isOccupied(Enemy *e);
};
#endif
