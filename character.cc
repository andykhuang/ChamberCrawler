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
	host = NULL;
	delete pot;
	pot = NULL;
}

void Character::setTile(Tile *t){
	host = t;
}

void Character::heal(int amount){
	if(hp + amount > maxhp) {
		hp = maxhp;
	} else if(hp + amount < 0) {
		hp = 0;
	} else {
		hp += amount;
	}
}

string Character::isSlain(Character *c){
	if(hp == 0) {
		//onDeath(c);
		return onDeath(c);
	}
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
