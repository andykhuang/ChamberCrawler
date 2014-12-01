#include "potion.h"
#include "player.h"
#include "boostatk.h"

using namespace std;

bool BoostAtk::hasEncountered = false;

void BoostAtk::resetEncounters() {
	hasEncountered = false;
}

BoostAtk::BoostAtk(AbstractPotion *p): Potion(p) {
	desc = "Boost Attack Potion";
	name = "BA";
}

int BoostAtk::getAtk(){
	return p->getAtk() + 5;
}

bool BoostAtk::isUsed(Player *pl) {
	hasEncountered = true;
	return isConsumed(pl);
}

bool BoostAtk::isUsed(Enemy *e) {
	return false;
}

string BoostAtk::seesPotion(){
	if(hasEncountered) return desc;
	return "Unknown Potion";
}
