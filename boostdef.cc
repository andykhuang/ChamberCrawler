#include "potion.h"
#include "player.h"
#include "boostdef.h"

using namespace std;

bool BoostDef::hasEncountered = false;

void BoostDef::resetEncounters() {
	hasEncountered = false;
}

BoostDef::BoostDef(AbstractPotion *p): Potion(p){
	desc = "Boost Defence Potion";
	name = "BD";
}

int BoostDef::getDef(){
	return p->getDef() + 5;
}

bool BoostDef::isUsed(Player *pl) {
	hasEncountered = true;
	return isConsumed(pl);
}

bool BoostDef::isUsed(Enemy *e) {
	return false;
}

string BoostDef::seesPotion(){
	if(hasEncountered) return desc;
	return "Unknown Potion";
}
