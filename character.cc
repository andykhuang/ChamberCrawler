#include <string>
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
	host = NULL;
	// TODO: Construct an empty potion here, ie a potion that does nothing
	pot = new EmptyPotion;
}

Character::Character(string race, int maxhp, int hp, int atk, int def):race(race), maxhp(maxhp), hp(hp), atk(atk), def(def){
	host = NULL;
	pot = new EmptyPotion;
}

Character::~Character(){
	delete host;
	host = NULL;
	delete pot;
	pot = NULL;
}

void Character::setTile(Tile *t) {
	host = t;
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
