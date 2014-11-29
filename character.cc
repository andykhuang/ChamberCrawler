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


string Character::isAttacked(Character *c){
	// Take damage
	return "";
}

bool Character::isDead(){
	return hp <= 0; 
}

ostream &operator<<(ostream &out, const Character &c){
	out << c.characterSymbol;
	return out;
}
