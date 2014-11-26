#include <string>
#include <iostream>
#include "tile.h"
#include "abstractpotion.h"
#include "potion.h"
#include "emptypotion.h"
#include "character.h"

using namespace std;

bool Character::attack(string dir){
	return false;
}

bool Character::move(string dir){
	return false;
}

bool Character::pickup(string dir){
	return false;
}

bool Character::use(string dir){
	return false;
}

Character::Character(){
	t = NULL;
	// TODO: Construct an empty potion here, ie a potion that does nothign
	pot = new EmptyPotion;
}

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

string Character::performAction(string command, string dir){
	return "Action";
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
