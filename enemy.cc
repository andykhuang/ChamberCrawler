#include <string>
#include <sstream>
#include "character.h"
#include "enemy.h"
#include "treasure.h"
#include "floor.h"
#include "tile.h"

using namespace std;

bool Enemy::onDeath(Character *c){
	return true;
}

// Gets a direction based on number or randomly if none is provided
string dirGet(int direction = -1){
	if(direction == -1) direction = Floor::random(0,7);
	if(direction == 0) return "nw";
	else if(direction == 1) return "no";
	else if(direction == 2) return "ne";
	else if(direction == 3) return "we";
	else if(direction == 4) return "ea";
	else if(direction == 5) return "sw";
	else if(direction == 6) return "so";
	else if(direction == 7) return "se";
	
	return "no";
}

string Enemy::performAction(string command, string dir){
	if(command != "" || dir != "") return "";
	// Enemy can only attack or move
	string actionResponse = "";
	// If the enemy is not a dragon
	// Check if there's a player around him to attack
	/*Tile **attackNeighbours = host->getNeighbour();
	string actionResponse = "";
	for(int i = 0; i < 8; i++){
		Character *tempCharacter = attackNeighbours[i]->getCharacterPtr();
		// If the tile has a character, check if it's a player
		if(tempCharacter != NULL && tempCharacter->isPlayer()){
			// then attack in that direction
			actionResponse += attack(dirGet(i));
			cout << "Rekt m8" << endl;
			return actionResponse;
		}
	}
	
	// If this is a dragon and it hasn't attacked yet
	// since a dragon can only attack once
	if(dynamic_cast<Dragon *>(this)){
		Tile **goldNeighbours = 
	}*/
	actionResponse = attack("");

	// if the enemy did not make an attack then move
	// Dragon's can't move
	if(actionResponse == ""){
		string direction = dirGet();
		int tries = 0; // incase an enemy gets boxed in so no infinite loops
		while(move(direction) == "" && tries < 20){
			// If i couldn't move in that direction, try to move in another 1
			direction = dirGet();
			tries++;
		}
	}
	return actionResponse;
}

string Enemy::isAttacked(Character *c){
	ostringstream oss;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	heal(-damage);
	oss << "deals " << damage << " to " << characterSymbol;
	oss << " (" << gethp() << " HP)";
	return oss.str();
}

string Enemy::move(string dir){
	// Get tile to step on
	Tile *dest = host->getNeighbour(dir);
	if(dest->isSteppedOn(this)){
		host->clearTile();
		host = dest;
		return "Moved";
	}
	return "";
}


string Enemy::attack(string dir){
	// TODO: Attack action
        return "";
}

// Enemy cannot pick up things
string Enemy::pickup(string dir){
        return "";
}


// Enemy cannot use things
string Enemy::use(string dir){
        return "";
}

Enemy::Enemy(){
	eTreasure = NULL;
	host = NULL;
}

Enemy::Enemy(string race, int maxhp, int hp, int atk, int def): Character(race, maxhp, hp, atk, def) {
	eTreasure = NULL;
	host = NULL;
}

bool Enemy::isPlayer(){
	return false;
}

Enemy::~Enemy(){
	delete eTreasure;
}
