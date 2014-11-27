#include "item.h"
#include "treasure.h"
#include "player.h"
#include "enemy.h"

using namespace std;

Treasure::Treasure(int value) : value(value){
	itemSymbol = 'G';
}

bool Treasure::canBeSteppedOn(Player *p){
	// Picks up the gold
	isPickedUp(p);
	return true;
}

bool Treasure::canBeSteppedOn(Enemy *e){
	return false;
}

bool Treasure::isPickedUp(Player *p){
	return true;
}

bool Treasure::isPickedUp(Enemy *e){
	return false;
}
