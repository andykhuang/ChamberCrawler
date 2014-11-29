#include "potion.h"
#include "player.h"
#include "boostatk.h"

using namespace std;

bool BoostAtk::hasEncountered = false;

BoostAtk::BoostAtk(AbstractPotion *p): Potion(p) {
	desc = "Boost Attack Potion";
	name = "BA";
}

int BoostAtk::getAtk(){
	return p->getAtk() + 5;
}

bool BoostAtk::isUsed(Player *pl) {
	// Wrap this Potion around the Potion the Player currently has
	p = pl->getPotion();
	// Set the Potion the Player currently has to this Potion
	pl->setPotion(this);
	hasEncountered = true;
	return true;
}

bool BoostAtk::isUsed(Enemy *e) {
	return false;
}
