#include "player.h"
#include "potion.h"
#include "poisonhealth.h"

using namespace std;

bool PoisonHealth::hasEncountered = false;

PoisonHealth::PoisonHealth(AbstractPotion *p): Potion(p) {
	desc = "Poison Health Potion";
	name = "PH";
}

bool PoisonHealth::isUsed(Player *p){
	isConsumed(p);
	p->heal(-10);
	hasEncountered = true;
	return true;
}

bool PoisonHealth::isUsed(Enemy *e){
	return false;
}
