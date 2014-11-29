#include "potion.h"
#include "player.h"
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

bool BoostDef::isUsed(Player *pl) {
	// Wrap this Potion around the Potion the Player currently has
	p = pl->getPotion();
	// Set the Potion the Player currently has to this Potion
	pl->setPotion(this);
	hasEncountered = true;
	return true;
}

bool BoostDef::isUsed(Enemy *e) {
	return false;
}
