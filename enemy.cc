#include <string>
#include <sstream>
#include "character.h"
#include "enemy.h"
#include "player.h"
#include "treasure.h"
#include "floor.h"
#include "tile.h"
#include "goblin.h"

using namespace std;

void Enemy::onDeath(Character *c){
	Player *p = dynamic_cast<Player *>(c);
	if(p) {
		eTreasure->isPickedUp(p);
		// Check if the killer is a Goblin
		Goblin *g = dynamic_cast<Goblin *>(p);
		// If the killer is a Goblin, give it an extra 5 gold
		if(g) {
			g->bank(5);
		}
	}
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

	actionResponse = attack();

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

	// If the Enemy attacked, append its characterSymbol to the actionResponse
	if(actionResponse != "") {
		actionResponse = " " + actionResponse;
		actionResponse = characterSymbol + actionResponse;
	}	

	return actionResponse;
}

string Enemy::isAttacked(Character *c){
	ostringstream oss;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	heal(-damage);
	oss << "deals " << damage << " damage to " << characterSymbol;
	oss << " (" << gethp() << " HP).";
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

string Enemy::attack(){
	string actionDesc = "";
	Tile **neighbours = host->getNeighbour();
	// Try to attack every Tile around this Enemy until one succeeds
	// or there are no more Tiles to attack
	for(int i = 0; i < 8 && actionDesc == ""; i++) {
		actionDesc = neighbours[i]->isAttacked(this);
	}
        return actionDesc;
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
