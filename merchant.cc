#include <string>
#include <sstream>
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
	ostringstream oss;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	heal(-damage);
	oss << "deals " << damage << " to " << characterSymbol << ".";
	return oss.str();
}
