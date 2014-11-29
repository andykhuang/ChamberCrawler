#include "player.h"
#include "potion.h"
#include "poisonhealth.h"

using namespace std;

bool PoisonHealth::hasEncountered = false;

PoisonHealth::PoisonHealth(AbstractPotion *p): Potion(p) {
	desc = "Poison Health Potion";
	name = "PH";
}

bool PoisonHealth::isUsed(Player *pl){
	pl->heal(-10);
	hasEncountered = true;
	return isConsumed(pl);
}

bool PoisonHealth::isUsed(Enemy *e){
	return false;
}
