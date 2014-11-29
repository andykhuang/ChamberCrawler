#include "abstractpotion.h"
#include "emptypotion.h"

using namespace std;

EmptyPotion::EmptyPotion() {
	name = "Empty Potion";
	desc = "Hey! This potion is completely empty!";
}

bool EmptyPotion::isUsed(Player *p) {
	return true;	
}

bool EmptyPotion::isUsed(Enemy *e) {
	return false;
}

int EmptyPotion::getAtk(){
	return 0;
}

int EmptyPotion::getDef(){
	return 0;
}
