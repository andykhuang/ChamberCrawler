#include "tile.h"
#include "passage.h"
#include "character.h"
#include "player.h"
#include "enemy.h"

using namespace std;

Passage::Passage(){
	tileSymbol = '#';
}


bool Passage::isSteppedOn(Player *p){
	// You can always step on a passage tile as a player
	character = p;
	return true;
}

bool Passage::isSteppedOn(Enemy *e){
	return false;
}

bool Passage::isOccupied(Enemy *e){
	return true;
}
