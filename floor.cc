#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "floor.h"
#include "tile.h"
#include "chamber.h"
#include "wall.h"
#include "doorway.h"
#include "passage.h"
#include "stairs.h"
#include "floortile.h"
#include "blanktile.h"
#include "character.h"
#include "player.h"
#include "item.h"
#include "potion.h"

using namespace std;

Floor::Floor(int lvl):defaultFile("defaultLayout.txt"){
	// TODO: MOVE THIS BODY INTO ANOTHER METHOD AND HAVE THE CONSTRUCTORS CALL IT WITH CERTAIN PARAMETERS
	this->lvl = lvl;
	maxEnemies = 20;
	maxPotions = 10;
	maxTreasures = 10;
	enemies = 0;
	potions = 0;
	treasures = 0;

	rSize = 25;
	cSize = 79;
	numChambers = 5;
	
	// Heap allocate a Floor of size rSize by cSize
	tiles = new Tile **[rSize];
	for(int i = 0; i < rSize; i++){
		tiles[i] = new Tile *[cSize];
	}

	// Heap allocate 5 chambers for the floor by default
	chambers = new Chamber *[numChambers];
	for(int i = 0; i < numChambers; i++){
		chambers[i] = NULL;
	}

	// Load the probability maps
	// Enemy
	eSpawnProb["Human"] = 4;
	eSpawnProb["Dwarf"] = 3;
	eSpawnProb["Halfling"] = 5;
	eSpawnProb["Elf"] = 2;
	eSpawnProb["Orc"] = 2;
	eSpawnProb["Merchant"] = 2;

	// Treasure
	tSpawnProb["Normal"] = 5;
	tSpawnProb["Dragon"] = 1;
	tSpawnProb["Small"] = 2;

	// Potions
	pSpawnProb["RH"] = 1;
	pSpawnProb["BA"] = 1;
	pSpawnProb["BD"] = 1;
	pSpawnProb["PH"] = 1;
	pSpawnProb["WA"] = 1;
	pSpawnProb["WD"] = 1;
	
	// TODO: Seed with system time
	srand(9001);
}

Floor::Floor(int lvl, int seed):defaultFile("defaultLayout.txt"){
	
}

Floor::~Floor(){
	// Delete Chambers
	for(int i = 0; i < numChambers; i++){
		delete chambers[i];
		chambers[i] = NULL;
	}
	delete [] chambers;
	chambers = NULL;
	
	// Delete tiles
	for(int i = 0; i < rSize; i++){
		for(int j = 0; j < cSize; j++){
			delete tiles[i][j];
			tiles[i][j] = NULL;
		}
		delete [] tiles[i];
		tiles[i] = NULL;
	}
	delete [] tiles;
	tiles = NULL;

}

void Floor::loadFloor(Player *p, Stairs *s){
	loadFloor(p, s, defaultFile);
}

void Floor::loadFloor(Player *p, Stairs *stairs, string fileName){
	// Set ifstream pointer
	ifstream f(fileName.c_str());
	string fLine;

	for(int i = 0; i < rSize; i++){
		getline(f, fLine);
		for(int j = 0; j < cSize; j++){
			char tempSymbol = fLine[j];
			// Vertical wall
			if(tempSymbol == '|'){
				tiles[i][j] = new Wall(true);
			}
			// Horizontal wall
			else if(tempSymbol == '-'){
				tiles[i][j] = new Wall(false);
			}

			// Floor
			else if(tempSymbol == '.'){
				tiles[i][j] = new FloorTile;
			}
			
			// Door
			else if(tempSymbol == '+'){
				tiles[i][j] = new Doorway;
			}

			// Walkway
			else if(tempSymbol == '#'){
				tiles[i][j] = new Passage;
			}
			// Blank tiles
			else if(tempSymbol == ' '){
				tiles[i][j] = new BlankTile;
			}
			else {
				//TODO: do we want to include this
				// should never get here
				cout << "Failure" << endl;
			}
		}
	}

	// TODO: Set Neighbours
	for(int r = 0; r < rSize; r++){
		for(int c = 0; c < cSize; c++){
			// Set neighbours here
			// if it's a blank tile or walls don't add neighbours
			// NORTHWEST Neighbour
			if(validCheck(r-1, c-1)){
				tiles[r][c]->addNeighbour(tiles[r-1][c-1]);
			}

			// NORTH
			if(validCheck(r-1, c)){
				tiles[r][c]->addNeighbour(tiles[r-1][c]);
			}
			
			// NORTHEAST
			if(validCheck(r-1, c+1)){
				tiles[r][c]->addNeighbour(tiles[r-1][c+1]);
			}

			// WEST
			if(validCheck(r, c-1)){
				tiles[r][c]->addNeighbour(tiles[r][c-1]);
			}

			// EAST
			if(validCheck(r, c+1)){
				tiles[r][c]->addNeighbour(tiles[r][c+1]);
			}

			// SOUTHWEST
			if(validCheck(r+1, c-1)){
				tiles[r][c]->addNeighbour(tiles[r+1][c-1]);
			}

			// SOUTH
			if(validCheck(r+1, c)){
				tiles[r][c]->addNeighbour(tiles[r+1][c]);
			}
			
			// SOUTHEAST
			if(validCheck(r+1, c+1)){
				tiles[r][c]->addNeighbour(tiles[r+1][c+1]);
			}
		}
	}

	// TrackerGrid a boolean grid to track whether a location has been visited before
	bool **trackerGrid = new bool *[rSize];
	// Init the trackerGrid
	for(int i = 0; i < rSize; i++){
		trackerGrid[i] = new bool [cSize];
		for(int j = 0; j < cSize; j++){
			trackerGrid[i][j] = false;
		}
	}
	
	// Begin Chamber Association
	for(int i = 0; i < numChambers; i++){
		// Sentienal for controlling search
		bool exitSearch = false;
		// Temporary Vector for storing the tiles associated with a chamber
		vector<Tile *> chamberTiles;

		// Traverse the 2D tile array looking for a floor
		for(int r = 0; r < rSize && !exitSearch; r++){
			for(int c = 0; c < cSize && !exitSearch; c++){
				char tempSymbol = tiles[r][c]->getTileSymbol();
				// If it's a floor tile type and not part of an existing chamber
				if(tempSymbol == '.' && !trackerGrid[r][c]){
					// Recursively push tile pointers to chamberTiles
					setChamber(r,c, chamberTiles, trackerGrid);
					// Constructs the chamber with chamberTiles vector
					chambers[i] = new Chamber(&chamberTiles[0], chamberTiles.size());
					exitSearch = true;
				}
			}
		}
	}

	// delete the trackerGrid
	for(int i = 0; i < rSize; i++){
		delete [] trackerGrid[i];
	}
	delete [] trackerGrid;

	// =================================
	// =	Begin Entity Generation	   =
	// =================================
	// Generate Order
	// 	- Player Location
	//		* CANNOT BE SAME ROOM AS STAIRS
	//		* EQUAL PROBABILITY FOR ALL CHAMBERS
	// 	- Stairway Location
	//		* ONLY 1 SET OF STAIRS GENERATED
	//		* SINGLETON?
	//		* EQUAL PROBABILITY FOR ALL CHAMBERS
	// 	- Potion locations
	//		* EQUAL PROBABILITY FOR ALL POTIONS
	//		* EQUAL PROBABILITY FOR ALL CHAMBERS
	//	- Gold Locations
	//		* EQUAL PROBABILITY FOR ALL CHAMBERS
	// 	- Enemy Locations
	//		* EQUAL PROBABILITY FOR ALL CHAMBERS
	// 	Remember that entity types can be generated with their respective functions
	// TODO: BEGIN
	// Randomly place into chambers (0 - numChambers-1)
	int chamberIndex;
	int playerChamberIndex;
	bool placeSucceeded = false;
	
	while (!placeSucceeded){
		// Generate Player Position
		chamberIndex = random(0, numChambers-1);	// Which chamber

		// Should only fail if chamber is full
		if(chambers[chamberIndex]->place(static_cast<Character *>(p))){
			placeSucceeded = true;
			playerChamberIndex = chamberIndex;
		}
		cout << "Player Placed" << endl;
	}
	// Reset Flag
	placeSucceeded = false;

	// Randomly Generate and place Stairs
	// Make sure not in the same chamber as player
	while(!placeSucceeded){
		chamberIndex = random(0, numChambers-1);
		// If not in the same room as the player
		if(chamberIndex != playerChamberIndex && chambers[chamberIndex]->place(stairs)){
			// TODO: this
			placeSucceeded = true;
		}
	}
	
	placeSucceeded = false;
	
}

// Random generation given a map of integers
// Sum of the map is the total probability
// Each individual key, value pair has probability/total probability of being returned
string Floor::random(map<string, int> &prob){
	int total = 0;

	// Calculate total probability
	for(map<string, int>::iterator i = prob.begin(); i != prob.end(); i++){
		total += i->second;
	}

	// Randomly generate between 0 and total
	int randNum = random(0, total);
	
	// Tracking current total
	int currentTotal = 0;
	for(map<string,int>::iterator i = prob.begin(); i != prob.end(); i++){
		currentTotal += i->second;
		if(randNum <= currentTotal){
			return i->first;
		}
	}
	return "";
}

// Generate a random number between low to high inclusive
int Floor::random(int low, int high){
	return (rand() % (high-low + 1)) + low;
}

void Floor::setChamber(int r, int c, vector<Tile *> &chamberTiles, bool **trackerGrid){
	// If it's not a valid coordinate or not a floor type tile then return
	if(!validCheck(r,c)|| trackerGrid[r][c] || tiles[r][c]->getTileSymbol() != '.'){
		return;
	} else {
		chamberTiles.push_back(tiles[r][c]);
		trackerGrid[r][c] = true;
		
		setChamber(r+1, c, chamberTiles, trackerGrid);
		setChamber(r-1, c, chamberTiles, trackerGrid);
		setChamber(r, c+1, chamberTiles, trackerGrid);
		setChamber(r, c-1, chamberTiles, trackerGrid);
	}
}

bool Floor::validCheck(int r, int c){
	if(r >= 0 && r < rSize && c >= 0 && c < cSize){
		return true;
	}
	return false;
}

ostream &operator<<(ostream &out, const Floor &f){
	for(int i = 0; i < f.rSize; i++){
		for(int j = 0 ; j < f.cSize; j++){
			out << *(f.tiles[i][j]);
		}
		out << endl;
	}
	return out;
}
