#include "item.h"
#include "treasure.h"
#include "player.h"
#include "enemy.h"

using namespace std;

Treasure::Treasure(int value) : value(value){
	itemSymbol = 'G';

	if(value == 1) {
		name = "Small Treasure";
		desc = "A small pile of gold. Probably worth a buck.";
	} else if(value == 2) {
		name = "Normal Treasure";
		desc = "An average pile of gold. Probably worth two bucks.";
	} else if(value == 4) {
		name = "Merchant Treasure";
		desc = "A sizeable pile of gold. Probably worth four bucks.";
	} else if(value == 6) {
		name = "Dragon Treasure";
		desc = "A dragon sized pile of gold. Worth only six bucks.";
	}
}

bool Treasure::canBeSteppedOn(Player *p){
	// Picks up the gold
	// isPickedUp(p);
	return isPickedUp(p);
}

bool Treasure::canBeSteppedOn(Enemy *e){
	return false;
}

bool Treasure::isPickedUp(Player *p){
	p->bank(value);
	return true;
}

bool Treasure::isPickedUp(Enemy *e){
	return false;
}
