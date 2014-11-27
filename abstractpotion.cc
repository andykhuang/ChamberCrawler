#include "item.h"
#include "abstractpotion.h"
#include "player.h"
#include "enemy.h"

using namespace std;

bool AbstractPotion::canBeSteppedOn(Player *p){
	return false;
}

bool AbstractPotion::canBeSteppedOn(Enemy *e){
	return false;
}
/*bool AbstractPotion::isUsed(Player *p){
	return false;
}

bool AbstractPotion::isUsed(Enemy *e){
	return false;
}*/
