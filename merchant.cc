#include <string>
#include <sstream>
#include "tile.h"
#include "merchant.h"
#include "vampire.h"
#include "treasure.h"

using namespace std;

bool Merchant::isFriendly = true;

void Merchant::resetFriendliness() {
	isFriendly = true;
}

Merchant::Merchant():Enemy("Merchant", 30, 30, 70, 5){
	eTreasure = new Treasure(4);
	characterSymbol = 'M';
}

string Merchant::attack(){
	string actionDesc = "";
	if(isFriendly) return actionDesc;
	Tile **neighbours = host->getNeighbour();
	// Try to attack every Tile around this Enemy until one succeeds
	// or there are no more Tiles to attack
	for(int i = 0; i < 8 && actionDesc == ""; i++) {
		actionDesc = neighbours[i]->isAttacked(this);
	}
        return actionDesc;
}

string Merchant::isAttacked(Character *c){
	isFriendly = false;
	ostringstream oss;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	heal(-damage);
	oss << "deals " << damage << " damage to " << *this;
	oss << " (" << gethp() << " HP). ";
	// If the attacker is a Vampire, they heal 5 HP from the attack
	if(dynamic_cast<Vampire *>(c)) {
		c->heal(5);
		oss << "PC leeches 5 HP from " << *this << ". ";
	}
	return oss.str();
}
