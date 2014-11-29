#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include "tile.h"
#include "chamber.h"

class Enemy;
class Player;
class AbstractPotion;
class Treasure;
class Stairs;

class Floor {
	// Private Constants
	const std::string defaultFile;

	// Private Fields
	// The current level
	int lvl;
	// The maximum number of enemies, potions, and treasures 
	int maxEnemies, maxPotions, maxTreasures;
	// The actual number of enemies, potions, and treasures currently on the floor
	int enemies, potions, treasures;
	// Column and row sizes of the floor
	int cSize, rSize;
	// Number of chambers
	int numChambers;

	// Stores the probability of spawning a specific mob
	// Enemy Spawn
	std::map<std::string, int> eSpawnProb;
	// Potion Spawn
	std::map<std::string, int> pSpawnProb;
	// Treasure Spawn
	std::map<std::string, int> tSpawnProb;
	
	Chamber **chambers;
	Tile ***tiles;

	// Private Methods
	std::string random(std::map<std::string, int>&);
	// Generate a random Enemy, Potion or Treasure based on their respective spawn probabilities
	Enemy* getEnemy();
	AbstractPotion* getPotion();
	Treasure* getTreasure();
	Stairs* getStairs();

	// Validity check
	bool validCheck (int r, int c);

	// Recursive chamber association
	void setChamber(int r, int c, std::vector<Tile *> &chamberTiles, bool **trackerGrid);
	
	public:
	// Constructors
	Floor(int lvl);
	Floor(int lvl, int seed);
	
	// Static function for generating random numbers
	static int random(int low, int high);
	// Load the default floor pattern
	void loadFloor(Player *p, Stairs *s);
	// Load the floor pattern from a specific input file
	void loadFloor(Player *p, Stairs *s, std::string fileName);
	// Enemy Action
	std::string enemyAction(Player *p);
	
	// Destructor
	~Floor();

	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};
#endif
