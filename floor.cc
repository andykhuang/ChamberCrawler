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
#include "floortile.h"
#include "blanktile.h"

using namespace std;

Floor::Floor(int lvl):defaultFile("defaultLayout.txt"){
	this->lvl = lvl;
	maxEnemies = 20;
	maxPotions = 10;
	maxTreasures = 10;
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
	
	// TODO: Seed with system time
	srand(1234);
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

string Floor::rand(map<std::string, int> prob){
	return "Randerp";
}

void Floor::loadFloor(){
	loadFloor(defaultFile);
}

void Floor::loadFloor(string fileName){
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
