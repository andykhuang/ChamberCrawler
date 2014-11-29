#include "player.h"
#include "potion.h"
#include "wounddef.h"

using namespace std;

bool WoundDef::hasEncountered = false;

WoundDef::WoundDef(AbstractPotion *p):Potion(p){
	desc = "Wound Defence Potion";
	name = "WD";
}

int WoundDef::getDef(){
	return p->getDef() - 5;
}

bool WoundDef::isUsed(Player *pl) {
	// Wrap this Potion around the Potion the Player currently has
	p = pl->getPotion();
	// Set the Potion the Player currently has to this Potion
	pl->setPotion(this);
	hasEncountered = true;
	return true;
}

bool WoundDef::isUsed(Enemy *e) {
	return false;
}
