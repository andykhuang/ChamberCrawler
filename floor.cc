#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "floor.h"
#include "tile.h"
#include "chamber.h"

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
	 //delete chambers
	 //delete tiles
}

string Floor::rand(map<std::string, int> prob){
	return "Randerp";
}

void Floor::loadFloor(){
	// Set ifstream pointer
	ifstream f(defaultFile.c_str());
	string fLine;

	for(int i = 0; i < rSize; i++){
		getline(f, fLine);
		for(int j = 0; j < cSize; j++){
			cout << fLine[j];
		}
		cout << endl;
	}
}

void Floor::loadFloor(string fileName){
	cout << "Load from file" << endl;
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
