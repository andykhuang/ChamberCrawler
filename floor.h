#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <cstdlib>

class Enemy;
class Player;
class Potion;
class Treasure;
class Stairs;

class Floor {
	// Private Constants
	const string defaultFile;

	// Private Fields
	int lvl;
	Cell ***cells;
	// Stores the probability of spawning a specific mob
	map<string, int> eSpawnProb;
	map<string, int> pSpawnProb;
	map<string, int> tSpawnProb;

	// Private Methods
	string rand(map<string, int>);	

	public:
	// Constructors
	Floor();
	Floor(int seed);
	// Load the default floor pattern
	void loadFloor();
	// Load the floor pattern from a specific input file
	void loadFloor(string fileName);
	// Generate a "random" enemy based on a set 
	Enemy getEnemy();
	Potion getPotion();
	Treasure getTreasure();
	Stairs getStairs();
	// Destructor
	~Floor();
}
#endif
