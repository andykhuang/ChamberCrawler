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

bool WoundAtk::isUsed(Player *p) {
	isConsumed(p);
	hasEncountered = true;
	return true;
}

bool WoundAtk::isUsed(Enemy *e) {
	return false;
}
