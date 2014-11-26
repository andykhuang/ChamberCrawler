#include "enemy.h"
#include "merchant.h"

using namespace std;

bool Merchant::isFriendly = true;

Merchant::Merchant(){
	// TODO: set stuff
	characterSymbol = 'M';
}

bool Merchant::isAttacked(Character *c){
	isFriendly = false;
	// Retaliate
	return true;
}
