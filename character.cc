#include <string>
#include "tile.h"
#include "potion.h"
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
	pot = NULL;
}

Character::~Character(){
	// delete stuff
}

string Character::performAction(string command, string dir){
	return "Action";
}

bool Character::isDead(){
	return hp <= 0; 
}
