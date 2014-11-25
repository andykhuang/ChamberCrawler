#include "player.h"
#include "enemy.h"
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

bool WoundDef::isUsed(Player *p) {
	isConsumed(p);
	hasEncountered = true;
	return true;
}

bool WoundDef::isUsed(Enemy *e) {
	return false;
}
