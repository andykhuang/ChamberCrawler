#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
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
#include "abstractpotion.h"
#include "potion.h"
#include "emptypotion.h"
#include "restorehealth.h"
#include "poisonhealth.h"
#include "boostatk.h"
#include "boostdef.h"
#include "woundatk.h"
#include "wounddef.h"
#include "treasure.h"
#include "dragontreasure.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

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
	
	srand(time(NULL));
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

void Floor::loadPreLoadedFloor(Player *p, Stairs *stairs, string fiveFloorFile){
	ifstream f(fiveFloorFile.c_str());
	string fLine;

	char **preFloor = new char *[rSize];
	for(int i = 0; i < rSize; i++){
		preFloor[i] = new char[cSize];
		for(int j = 0; j < cSize; j++){
			preFloor[i][j] = ' ';
		}
	}

	//Skip lines
	for(int i = 0; i < rSize*(lvl-1); i++){
		getline(f, fLine);
	}

	// Start reading
	for(int i = 0; i < rSize; i++){
		getline(f, fLine);
		for(int j = 0; j < cSize; j++){
			preFloor[i][j] = fLine[j];
		}
	}
	
	// Step 1: Construct a blank floor with only walls, doors, passages blanktiles, and floors (floor is everything that is not one of the 4 aforementioned things)
	for(int i = 0; i < rSize; i++){
		for(int j = 0; j < cSize; j++){
			if(preFloor[i][j] == '|'){
				tiles[i][j] = new Wall(true);
			}
			// Horizontal wall
			else if(preFloor[i][j]  == '-'){
				tiles[i][j] = new Wall(false);
			}
			
			// Door
			else if(preFloor[i][j] == '+'){
				tiles[i][j] = new Doorway;
			}

			// Walkway
			else if(preFloor[i][j]  == '#'){
				tiles[i][j] = new Passage;
			}
			// Blank tiles
			else if(preFloor[i][j]  == ' '){
				tiles[i][j] = new BlankTile;
			}

			// Treat as floor tiles
			else {
				tiles[i][j] = new FloorTile;
			}
			
		}
	}
	// Set neighbours for tiles
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

	// Note chambers are not necessary because be don't need random generation and placement
	// Step 2: Load all potions

	// Step 3: Load all Treasures, if a 9 (dragon hoard) is encountered, search the surrounding space for a D, set both the DragonTreasure tile and the dragon tile simultaneously
	
	// Step 4: Load all enemies except dwarfs
	// Step 5: Load dwarfs
	
	for(int i = 0; i < rSize; i++){
		for(int j = 0; j < cSize; j++){
			char tmp = preFloor[i][j];
			bool isDragon = false;
			// Potions
			Item *tmpItem = NULL;
			Character *tmpChar = NULL;
			if(tmp == '0') tmpItem = new RestoreHealth(NULL);
			else if(tmp == '1') tmpItem = new BoostAtk(NULL);
			else if(tmp == '2') tmpItem = new BoostDef(NULL);
			else if(tmp == '3') tmpItem = new PoisonHealth(NULL);
			else if(tmp == '4') tmpItem = new WoundAtk(NULL);
			else if(tmp == '5') tmpItem = new WoundDef(NULL);
			else if(tmp == '6') tmpItem = new Treasure(2);
			else if(tmp == '7') tmpItem = new Treasure(1);
			else if(tmp == '8') tmpItem = new Treasure(4);
			else if(tmp == '9'){
				isDragon = true;
				Tile *dragonTile = NULL;
				// NORTH WEST
				if(validCheck(i-1, j-1)){
					if(preFloor[i-1][j-1] == 'D') dragonTile = tiles[i-1][j-1];
				}

				// NORTH
				if(validCheck(i-1, j)){
					if(preFloor[i-1][j] == 'D') dragonTile = tiles[i-1][j];
				}
				
				// NORTHEAST
				if(validCheck(i-1, j+1)){
					if(preFloor[i-1][j+1] == 'D') dragonTile = tiles[i-1][j+1];
				}

				// WEST
				if(validCheck(i, j-1)){
					if(preFloor[i][j-1] == 'D') dragonTile = tiles[i][j-1];
				}

				// EAST
				if(validCheck(i, j+1)){
					if(preFloor[i][j+1] == 'D') dragonTile = tiles[i][j+1];
				}

				// SOUTHWEST
				if(validCheck(i+1, j-1)){
					if(preFloor[i+1][j-1] == 'D') dragonTile = tiles[i+1][j-1];
				}

				// SOUTH
				if(validCheck(i+1, j)){
					if(preFloor[i+1][j] == 'D') dragonTile = tiles[i+1][j];
				}
				
				// SOUTHEAST
				if(validCheck(i+1, j+1)){
					if(preFloor[i+1][j+1] == 'D') dragonTile = tiles[i+1][j+1];
				}
				
				tmpItem = new DragonTreasure(dragonTile, tiles[i][j]);
				tiles[i][j]->placeItem(tmpItem);
			
			}
			else if(tmp == 'H') tmpChar = new Human;
			else if(tmp == 'E') tmpChar = new Elf;
			else if(tmp == 'O') tmpChar = new Orc;
			else if(tmp == 'M') tmpChar = new Merchant;
			else if(tmp == 'L') tmpChar = new Halfling;
			else if(tmp == '@') tmpChar = p;
			else if(tmp == '\\') tmpItem = stairs;

			if(!isDragon && tmpItem != NULL){
				tmpItem->setHost(tiles[i][j]);
				tiles[i][j]->placeItem(tmpItem);
			}
			if(tmpChar != NULL){
				tmpChar->setTile(tiles[i][j]);
				tiles[i][j]->placeCharacter(tmpChar);
			}
			isDragon = false;
		}
	}

	// Generate Dwarves
	for(int i = 0; i < rSize; i++){
		for(int j = 0; j < cSize; j++){
			if(preFloor[i][j] == 'D'){
				if(!tiles[i][j]->isOccupied()){
					Dwarf *tempDwarf = new Dwarf;
					tempDwarf->setTile(tiles[i][j]);
					tiles[i][j]->placeCharacter(tempDwarf);
				}
			}
		}
	}

	// Free the preFloor 2D char array
	for(int i = 0; i < rSize; i++){
		delete [] preFloor[i];
	}
	delete [] preFloor;
}

void Floor::loadFloor(Player *p, Stairs *stairs){
	loadFloor(p, stairs, defaultFile);
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
	// Temp int for random generation
	int chamberIndex;
	// Stores the chamber player is in so stairs won't be in the same one
	int playerChamberIndex;
	// Temp Flag denoting the success of a placement
	bool placeSucceeded = false;
	
	while (!placeSucceeded){
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
			placeSucceeded = true;
		}
		cout << "Stairs Placed" << endl;
	}
	
	placeSucceeded = false;


	// Randomly generate and place potions
	for(int i = potions; i < maxPotions; i++){
		while(!placeSucceeded){
			// Generate Type of Potion
			Item *tempPotion = getPotion();
			// Generate Chamber
			chamberIndex = random(0, numChambers-1);
			if(chambers[chamberIndex]->place(tempPotion)){
				placeSucceeded = true;
			}
		}
		placeSucceeded = false;
	}
	
	// Randomly generate and place gold
	// Special Note that There must be at least 1 neighbour that's not occupied around the gold
	for(int i = treasures; i < maxTreasures; i++){
		while(!placeSucceeded){
			// Generate the type of Treasure
			Item *tempTreasure = getTreasure();
			// Generate Chamber
			chamberIndex = random(0, numChambers-1);
			if(chambers[chamberIndex]->place(tempTreasure)){
				placeSucceeded = true;
			}
		}
		placeSucceeded = false;
	}

	// Randomly generate and place enemies
	for(int i = enemies; i < maxEnemies; i++){
		while(!placeSucceeded){
			// Generate the type of Enemy
			Character *tempEnemy = getEnemy();
			// Generate the Chamber
			chamberIndex = random(0, numChambers-1);
			if(chambers[chamberIndex]->place(tempEnemy)){
				placeSucceeded = true;
			}
		}
		placeSucceeded = false;
	}
	
}

Enemy* Floor::getEnemy(){
	Enemy *toReturn;
	string eType = random(eSpawnProb);

	if(eType == "Human"){
		toReturn = new Human;
	} else if(eType == "Dwarf"){
		toReturn = new Dwarf;
	} else if(eType == "Halfling"){
		toReturn = new Halfling;
	} else if(eType == "Elf"){
		toReturn = new Elf;
	} else if(eType == "Orc"){
		toReturn = new Orc;
	} else if(eType == "Merchant"){
		toReturn = new Merchant;
	} else {
		toReturn = NULL;
	}
	return toReturn;
}

Treasure* Floor::getTreasure(){
	Treasure *toReturn;
	string tType = random(tSpawnProb);
	
	if(tType == "Normal"){
		toReturn = new Treasure(2);
	} else if(tType == "Small"){
		toReturn = new Treasure(1);
	} else if(tType == "Dragon"){
		toReturn = new DragonTreasure;
		// Since a dragon hoard always comes with a dragon
		enemies++;
	} else {
		toReturn = NULL;
	}
	return toReturn;
}

// TODO: Decorate the potion
AbstractPotion* Floor::getPotion(){
	AbstractPotion *toReturn = NULL;
	string potType = random(pSpawnProb);

	if(potType == "BA"){
		toReturn = new BoostAtk(NULL);
	} else if(potType == "WA"){
		toReturn = new WoundAtk(NULL);
	} else if(potType == "BD"){
		toReturn = new BoostDef(NULL);
	} else if(potType == "WD"){
		toReturn = new WoundDef(NULL);
	} else if(potType == "RH"){
		toReturn = new RestoreHealth(NULL);
	} else if(potType == "PH"){
		toReturn = new PoisonHealth(NULL);
	} else {
		toReturn = NULL;
	}

	return toReturn;
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

string Floor::enemyAction(Player *p){
	string actionDesc = "";
	vector<Character *> characterArray;
	// Map out all the characters
	for(int i = 0; i < rSize; i++){
		for(int j = 0; j < cSize; j++){
			// if there is a character on the tile (ie not null)
			Character *temp = tiles[i][j]->getCharacterPtr();
			if(temp != NULL){
				characterArray.push_back(temp);
			}
		}
	}
	
	// call the perform action function for each character
	int vectorSize = characterArray.size();
	for(int i = 0; i < vectorSize; i++){
		actionDesc += characterArray[i]->performAction();
	}
	return actionDesc;
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
