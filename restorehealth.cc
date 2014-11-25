#include "potion.h"
#include "restorehealth.h"
#include "player.h"
#include "enemy.h"

using namespace std;

bool RestoreHealth::hasEncountered = false;

RestoreHealth::RestoreHealth(AbstractPotion *p): Potion(p) {
	name = "RH";
	desc = "Restore Health Potion";
}

bool RestoreHealth::isUsed(Player *p){
	isConsumed(p);
	p->heal(10);
	hasEncountered = true;
	return true;
}

bool RestoreHealth::isUsed(Enemy *e){
	return false;
}
