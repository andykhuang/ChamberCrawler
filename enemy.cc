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

string randDir(){
	int direction = Floor::random(0,7);
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
	// Enemy can only attack or move
	// Check if there's a player around him to attack
	if(false){
		return "";
	} 
	// Move randomly
	else {
		string direction = randDir();
		while(!move(dir)){
			
		}
	}
	// Otherwise Move
	return "Enemy perform Action";
}

string Enemy::isAttacked(Character *c){
	ostringstream oss;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	heal(-damage);
	oss << "deals " << damage << " to " << characterSymbol;
	return oss.str();
}

bool Enemy::move(string dir){
	// Get tile to step on
	Tile *dest = host->getNeighbour(dir);
	if(dest->isSteppedOn(this)){
		host->clearTile();
		host = dest;
		return true;
	}
	return false;
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

Enemy::~Enemy(){
	delete eTreasure;
}
