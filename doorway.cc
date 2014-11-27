#include "tile.h"
#include "doorway.h"
#include "enemy.h"
#include "player.h"
#include "character.h"

using namespace std;

Doorway::Doorway(){
	tileSymbol = '+';
}

bool Doorway::isOccupied(Enemy *c){
	return true;
}

bool Doorway::isSteppedOn(Enemy *e){
	return false;
}

bool Doorway::isSteppedOn(Player *p){
	// Players can always step on doorways
	character = p;
	return true;
}
