#include "item.h"
#include "abstractpotion.h"
#include "player.h"
#include "enemy.h"

using namespace std;

AbstractPotion::AbstractPotion() {
	itemSymbol = 'P';
}
AbstractPotion::~AbstractPotion() {}

bool AbstractPotion::canBeSteppedOn(Player *p){
	return false;
}

bool AbstractPotion::canBeSteppedOn(Enemy *e){
	return false;
}

bool AbstractPotion::isPickedUp(Player *p) {
	return isUsed(p);
}

bool AbstractPotion::isPickedUp(Enemy *e) {
	return isUsed(e);
}
