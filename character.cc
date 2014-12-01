#include <string>
#include <iostream>
#include "tile.h"
#include "abstractpotion.h"
#include "potion.h"
#include "emptypotion.h"
#include "character.h"

using namespace std;

Character::Character(){
	host = NULL;
	pot = new EmptyPotion;
}

// A Character constructor that accepts some parameters for the character's stats
Character::Character(string race, int maxhp, int hp, int atk, int def):race(race), maxhp(maxhp), hp(hp), atk(atk), def(def){
	host = NULL;
	pot = new EmptyPotion;
}

Character::~Character(){
	// Does not delete the host Tile since Floor deletes all Tiles
	host = NULL;
	delete pot;
	pot = NULL;
}

void Character::setTile(Tile *t){
	host = t;
}

void Character::heal(int amount){
	// Ensure the hp value does not exceed maxhp or go lower than 0
	if(hp + amount > maxhp) {
		hp = maxhp;
	} else if(hp + amount < 0) {
		hp = 0;
	} else {
		hp += amount;
	}
}

string Character::isSlain(Character *c){
	// Check if this Character is "dead" (hp == 0)
	// If true, return a message about its death
	if(hp == 0) {
		return onDeath(c);
	}
	// Otherwise return an empty string
	return ""; 
}

string Character::getRace(){
	return race;
}

int Character::gethp(){
	return hp;
}

int Character::getatk(){
	return atk;
}

int Character::getdef(){
	return def;
}

ostream &operator<<(ostream &out, const Character &c){
	out << c.characterSymbol;
	return out;
}
