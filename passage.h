#ifndef ___PASSAGE_H___
#define ___PASSAGE_H___

class Enemy;

class Passage: public Tile {
	public:
	// Constructor
	Passage();

	// Override the isOccupied for Enemies to always return True
	bool isOccupied(Enemy *e);
};
#endif
