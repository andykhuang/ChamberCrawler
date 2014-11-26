#include "item.h"
#include "treasure.h"

using namespace std;

Treasure::Treasure(int value) : value(value){
	itemSymbol = 'G';
}

bool Treasure::isPickedUp(Player *p){
	return true;
}

bool Treasure::isPickedUp(Enemy *e){
	return false;
}
