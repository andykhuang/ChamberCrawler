#include <string>
#include "abstractpotion.h"
#include "emptypotion.h"

using namespace std;

EmptyPotion::EmptyPotion() {
	name = "Empty Potion";
	desc = "Hey! This potion is completely empty!";
}

int EmptyPotion::getAtk(){
	return 0;
}

int EmptyPotion::getDef(){
	return 0;
}

bool EmptyPotion::isUsed(Player *p) {
	return true;	
}

bool EmptyPotion::isUsed(Enemy *e) {
	return false;
}

bool EmptyPotion::isPickedUp(Player *p) {
	return true;	
}

bool EmptyPotion::isPickedUp(Enemy *e) {
	return false;
}
