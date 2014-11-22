#include <string>
#include <iostream>
#include "floor.h"
#include "tile.h"
#include "chamber.h"

using namespace std;

Floor::Floor(int lvl):defaultFile("defaultLayout.txt"){
	this->lvl = lvl;
	maxEnemies = 20;
	maxPotions = 10;
	maxTreasures = 10;

	// Store Probabilities
	// Heap Allocate Chambers
	// Heap Allocate Tiles
	// Seed with system time
}

Floor::Floor(int lvl, int seed){

}

Floor::~Floor(){
	// delete chambers
	// delete tiles
}

string Floor::rand(map<std::string, int> prob){
	return "Randerp";
}

void Floor::loadFloor(){
	cout << "Load Floor" << endl;
}

void Floor::loadFloor(string fileName){
	cout << "Load from file" << endl;
}
