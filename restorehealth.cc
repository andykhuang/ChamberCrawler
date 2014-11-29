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
	// Wrap this Potion around the Potion the Player currently has
	p = pl->getPotion();
	// Set the Potion the Player currently has to this Potion
	pl->setPotion(this);
	pl->heal(10);
	hasEncountered = true;
	return true;
}

bool RestoreHealth::isUsed(Enemy *e){
	return false;
}
