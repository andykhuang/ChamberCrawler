#include <string>
#include <sstream>
#include "character.h"
#include "enemy.h"
#include "player.h"
#include "vampire.h"
#include "treasure.h"
#include "floor.h"
#include "tile.h"
#include "goblin.h"

using namespace std;

string Enemy::onDeath(Character *c){
	ostringstream oss;
	oss << *this << " has been slain. ";
	Player *p = dynamic_cast<Player *>(c);
	if(p) {
		eTreasure->isPickedUp(p);
		// Check if the killer is a Goblin
		Goblin *g = dynamic_cast<Goblin *>(p);
		// If the killer is a Goblin, give it an extra 5 gold
		if(g) {
			g->bank(5);
			oss << 5 + eTreasure->getValue();
		} else {
			oss << eTreasure->getValue();
		}
		oss << " gold was looted. ";
	}

	// Return a string detailing this death
	return oss.str();
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

	// If this Enemy did not make an attack then make a move
	// NOTE: Dragons will try to move but not go anywhere
	if(actionResponse == ""){
		// Generate a random direction for this Enemy to move in
		string direction = dirGet();
		int tries = 0; // Incase an enemy gets boxed in so no infinite loops
		while(move(direction) == "" && tries < 20){
			// If the move failed, try again
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
	// Calculate the damage taken from the attack
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	heal(-damage);

	oss << "deals " << damage << " damage to " << *this;
	oss << " (" << gethp() << " HP). ";
	// If the attacker is a Vampire, they heal 5 HP from the attack
	if(dynamic_cast<Vampire *>(c)) {
		c->heal(5);
		oss << "PC leeches 5 HP from " << *this << ". ";
	}

	// Return a string detailing the attack
	return oss.str();
}

string Enemy::move(string dir){
	// Get Tile to move to
	Tile *dest = host->getNeighbour(dir);
	// Try to step on that Tile
	if(dest->isSteppedOn(this)){
		// If the Tile can be stepped on, move to that Tile
		host->clearTile();
		host = dest;
		// Return a string saying the move was successful
		return "Moved";
	}
	// If the move failed, return an empty string
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
