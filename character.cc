#include <string>
#include <iostream>
#include "tile.h"
#include "abstractpotion.h"
#include "potion.h"
#include "emptypotion.h"
#include "character.h"

using namespace std;


Character::Character(){
	t = NULL;
	pot = new EmptyPotion;
}

// A Character constructor that accepts some parameters for the character's stats
Character::Character(string race, int maxhp, int hp, int atk, int def):race(race), maxhp(maxhp), hp(hp), atk(atk), def(def){
	t = NULL;
	pot = new EmptyPotion;
}

Character::~Character(){
	t = NULL;
	delete pot;
	pot = NULL;
}

void Character::setTile(Tile *t){
	this->t = t;
}


bool Character::isAttacked(Character *c){
	// Take damage
	return true;
}

bool Character::isDead(){
	return hp <= 0; 
}

ostream &operator<<(ostream &out, const Character &c){
	out << c.characterSymbol;
	return out;
}
