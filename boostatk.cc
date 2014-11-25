#include "player.h"
#include "enemy.h"
#include "potion.h"
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

bool BoostAtk::isUsed(Player *p) {
	// Wrap this Potion around the Potion the Player currently has
	this->setPotion(p->getPotion());
	// Set the Potion the Player currently has to this Potion
	p->setPotion(this);
	hasEncountered = true;
	return true;
}

bool BoostAtk::isUsed(Enemy *e) {
	return false;
}
