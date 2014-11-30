#include <string>
#include <sstream>
#include "halfling.h"
#include "enemy.h"
#include "treasure.h"
#include "floor.h"

using namespace std;

Halfling::Halfling(): Enemy("Halfling", 100, 100, 15, 20){
	eTreasure = new Treasure(Floor::random(1, 2));
	characterSymbol = 'L';
}

string Halfling::isAttacked(Character *c){
	ostringstream oss;
	int miss = Floor::random(1, 2);
	if(miss == 1) {
		oss << "missed " << *this << ". ";
	} else {
		int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
		heal(-damage);
		oss << "deals " << damage << " damage to " << *this;
		oss << " (" << gethp() << " HP). ";
	}
	return oss.str();
}
