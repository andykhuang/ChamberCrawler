#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <cstdlib>
#include <iostream>
#include "tile.h"
#include "chamber.h"

class Enemy;
class Player;
class Potion;
class Treasure;
class Stairs;

class Floor {
	// Private Constants
	const string defaultFile;

	// Private Fields
	// The current level
	int lvl;
	// The maximum number of enemies, potions, and treasures 
	int maxEnemies, maxPotions, maxTreasures;
	// Stores the probability of spawning a specific mob
	map<std::string, int> eSpawnProb;
	map<std::string, int> pSpawnProb;
	map<std::string, int> tSpawnProb;
	
	Chamber **chambers;
	Tile ***tiles;

	// Private Methods
	string rand(map<std::string, int>);	
	// Generate a random Enemy, Potion or Treasure based on their respective spawn probabilities
	Enemy getEnemy();
	Potion getPotion();
	Treasure getTreasure();
	Stairs getStairs();
	
	public:
	// Constructors
	Floor();
	Floor(int seed);
	
	// Load the default floor pattern
	void loadFloor();
	// Load the floor pattern from a specific input file
	void loadFloor(std::string fileName);	

	// Destructor
	~Floor();

	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
}
#endif
