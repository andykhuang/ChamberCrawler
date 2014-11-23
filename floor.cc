#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
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
	
	// Store Probabilities
	// Heap Allocate Chambers
	// Heap Allocate Tiles
	tiles = new Tile **[rSize];
	for(int i = 0; i < rSize; i++){
		tiles[i] = new Tile *[cSize];
	}
	// Seed with system time
}

Floor::Floor(int lvl, int seed):defaultFile("defaultLayout.txt"){
	
}

Floor::~Floor(){
	// TODO: delete chambers
	// Delete tiles
	for(int i = 0; i < rSize; i++){
		for(int j = 0; j < cSize; j++){
			delete tiles[i][j];
		}
		delete [] tiles[i];
	}
	delete [] tiles;

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

	// TODO: Associate chambers with tiles (possibly using recursion)
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
