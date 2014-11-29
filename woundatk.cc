#include "player.h"
#include "potion.h"
#include "woundatk.h"

using namespace std;

bool WoundAtk::hasEncountered = false;

WoundAtk::WoundAtk(AbstractPotion *p) : Potion(p){
	desc = "Wound Attack Potion";
	name = "WA";
}

int WoundAtk::getAtk(){
	return p->getAtk() - 5;
}

bool WoundAtk::isUsed(Player *pl) {
	// Wrap this Potion around the Potion the Player currently has
	p = pl->getPotion();
	// Set the Potion the Player currently has to this Potion
	pl->setPotion(this);
	hasEncountered = true;
	return true;
}

bool WoundAtk::isUsed(Enemy *e) {
	return false;
}
