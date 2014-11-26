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
	isConsumed(p);	
	hasEncountered = true;
	return true;
}

bool BoostAtk::isUsed(Enemy *e) {
	return false;
}
