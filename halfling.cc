#include <string>
#include <sstream>
#include "halfling.h"
#include "vampire.h"
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
	// Check if the Player missed their attack on this Halfling
	int miss = Floor::random(1, 2);
	if(miss == 1) {
		oss << "missed " << *this << ". ";
	} else {
		// Calculate the damage from the attack
		int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
		heal(-damage);

		oss << "deals " << damage << " damage to " << *this;
		oss << " (" << gethp() << " HP). ";

		// If the attacker is a Vampire, they heal 5 HP from the attack
		if(dynamic_cast<Vampire *>(c)) {
			c->heal(5);
			oss << "PC leeches 5 HP from " << *this << ". ";
		}
	}
	// Return a string detailing the attack
	return oss.str();
}
