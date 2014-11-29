#include <string>
#include "merchant.h"

using namespace std;

bool Merchant::isFriendly = true;

Merchant::Merchant(){
	// TODO: set stuff
	characterSymbol = 'M';
}

string Merchant::isAttacked(Character *c){
	isFriendly = false;
	// Retaliate
	return "";
}
