#include "enemy.h"
#include "merchant.h"

using namespace std;

Merchant::Merchant(){
	isFriendly = true;
	// TODO: set stuff
}

bool Merchant::isAttacked(Character *c){
	isFriendly = false;
	// Retaliate
	return true;
}
