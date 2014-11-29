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
	// Wrap this Potion around the Potion the Player currently has
	p = pl->getPotion();
	// Set the Potion the Player currently has to this Potion
	pl->setPotion(this);
	pl->heal(-10);
	hasEncountered = true;
	return true;
}

bool PoisonHealth::isUsed(Enemy *e){
	return false;
}
