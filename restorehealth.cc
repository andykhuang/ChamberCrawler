#include "player.h"
#include "potion.h"
#include "restorehealth.h"

using namespace std;

bool RestoreHealth::hasEncountered = false;

RestoreHealth::RestoreHealth(AbstractPotion *p): Potion(p) {
	name = "RH";
	desc = "Restore Health Potion";
}

bool RestoreHealth::isUsed(Player *pl){
	pl->heal(10);
	hasEncountered = true;
	return isConsumed(pl);
}

bool RestoreHealth::isUsed(Enemy *e){
	return false;
}

string RestoreHealth::seesPotion(){
	if(hasEncountered) return desc;
	return "Unknown Potion";
}
