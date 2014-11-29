#ifndef ___TILE_H___
#define ___TILE_H___
#include <iostream>
#include <string>

class Character;
class Player;
class Item;
class Enemy;

const int MAX_NEIGHBOURS = 8;

class Tile {
	protected:
	int numNeighbours;
	Tile *neighbours[MAX_NEIGHBOURS];

	Item *item;
	Character *character;
	char tileSymbol;

	public:
	// Constructors
	Tile();
	Tile(Character *c);
	Tile(Item *i);

	// Returns whether this Tile has something "on" it
	virtual bool isOccupied();
	// TODO: Remove this
	virtual bool isOccupied(Player *p);
	virtual bool isOccupied(Enemy *e);
	// Tries to place a Character on this Tile and return whether it succeeded
	virtual bool placeCharacter(Character *c);
	// Tries to place an Item on this Tile and return whether it succeeded
	virtual bool placeItem(Item *i);
	// Try to step on this Tile and return whether it succeeded
	virtual bool isSteppedOn(Player *p);
	virtual bool isSteppedOn(Enemy *e);
	// Try to attack this Tile and return a message describing the
	// attack or an empty string if the Tile cannot be attacked
	virtual std::string isAttacked(Player *p);
	virtual std::string isAttacked(Enemy *e);

	virtual std::string isUsed(Player *p);
	virtual std::string isPickedUp(Player *p);

	// Sets the Item and Character pointers to NULL (Does not delete)
	/*virtual*/void clearTile();

	// Sets the Item pointer to NULL and called Delete on the Item
	// This should only be called when picking up Treasure
	/*virtual*/void removeTreasure();

	// Add Neighbours
	void addNeighbour(Tile *neighbour);
	
	// Get Neighbours
	Tile* getNeighbour(std::string dir);
	Tile** getNeighbour();

	// Get tileSymbol
	char getTileSymbol();

	// Destructor
	virtual ~Tile() = 0;

	// TODO: Remove this
	void setTileSymbol(char s){
		tileSymbol = s;
	}

	friend std::ostream &operator<<(std::ostream &out, const Tile &t);
};
#endif
