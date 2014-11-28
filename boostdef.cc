#include "potion.h"
#include "boostdef.h"

using namespace std;

bool BoostDef::hasEncountered = false;

BoostDef::BoostDef(AbstractPotion *p): Potion(p){
	desc = "Boost Defence Potion";
	name = "BD";
}

int BoostDef::getDef(){
	return p->getDef() + 5;
}

bool BoostDef::isUsed(Player *p) {
	isConsumed(p);
	hasEncountered = true;
	return true;
}

bool BoostDef::isUsed(Enemy *e) {
	return false;
}
