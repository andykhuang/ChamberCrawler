#include <string>
#include "merchant.h"
#include "treasure.h"

using namespace std;

bool Merchant::isFriendly = true;

Merchant::Merchant():Enemy("Merchant", 30, 30, 70, 5){
	// TODO: set stuff
	eTreasure = new Treasure(4);
	characterSymbol = 'M';
}

string Merchant::isAttacked(Character *c){
	isFriendly = false;
	// Retaliate
	return "";
}
