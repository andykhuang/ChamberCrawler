#include <cstdlib>
#include <string>
#include <sstream>
#include "abstractpotion.h"
#include "player.h"
#include "drow.h"

using namespace std;

Drow::Drow(): Player("Drow", 150, 150, 25, 15) {}

int Drow::getatk() {
	// Want to maintain the integer-ness of the atk value
	return atk + ((15 * pot->getAtk()) / 10);
}

int Drow::getdef() {
	// Want to maintain the integer-ness of the def value
	return def + ((15 * pot->getAtk()) / 10);
}

void Drow::heal(int amount) {
	// To maintain the integer-ness of the values
	int effective_amount = (15*amount)/10;

	// Check to ensure the updated hp value is between maxhp and 0 (inclusive)
	if(hp + effective_amount > maxhp) {
		hp = maxhp;
	} else if(hp + effective_amount < 0) {
		hp = 0;
	} else {
		hp += effective_amount;
	}
}

string Drow::isAttacked(Character *c){
	ostringstream oss;
	int miss = rand() % 2;

	// Check to see if the attack missed
	if(miss == 1) {
		oss << "missed PC. ";
	} else {
		// If the attack did not miss, calculate the damage it dealt
		// NOTE: Drow does not get attacked twice by Elves
		int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
		heal(-damage);
		oss << "deals " << damage << " damage to PC. ";
	}

	// Return a string detailing the attack
	return oss.str();
}
