#include "abstractpotion.h"
#include "emptypotion.h"

using namespace std;

bool EmptyPotion::isPickedUp(Player *p){
	return true;
}

bool EmptyPotion::isPickedUp(Enemy *e){
	return false;
}

int EmptyPotion::getAtk(){
	return 0;
}

int EmptyPotion::getDef(){
	return 0;
}
