#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <cstdlib>
#include <map>
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
	const std::string defaultFile;

	// Private Fields
	// The current level
	int lvl;
	// The maximum number of enemies, potions, and treasures 
	int maxEnemies, maxPotions, maxTreasures, cSize, rSize;
	// Stores the probability of spawning a specific mob
	std::map<std::string, int> eSpawnProb;
	std::map<std::string, int> pSpawnProb;
	std::map<std::string, int> tSpawnProb;
	
	Chamber **chambers;
	Tile ***tiles;

	// Private Methods
	std::string rand(std::map<std::string, int>);	
	// Generate a random Enemy, Potion or Treasure based on their respective spawn probabilities
	Enemy getEnemy();
	Potion getPotion();
	Treasure getTreasure();
	Stairs getStairs();
	
	public:
	// Constructors
	Floor(int lvl);
	Floor(int lvl, int seed);
	
	// Load the default floor pattern
	void loadFloor();
	// Load the floor pattern from a specific input file
	void loadFloor(std::string fileName);	

	// Destructor
	~Floor();

	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};
#endif
