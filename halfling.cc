#include "halfling.h"
#include "enemy.h"

Halfling::Halfling(){
	characterSymbol = 'L';
}

bool Halfling::isAttacked(Character *p){
	return true;
}
