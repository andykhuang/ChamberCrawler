#ifndef ___WALL_H___
#define ___WALL_H___

class Player;
class Enemy;

class Wall: public Tile {
	public:
	// Constructor
	Wall(bool isVertical);

	// Overrides for the isOccupied methods
	bool isOccupied(Player *p);
	bool isOccupied(Enemy *e);
};
#endif
