#include <string>
#include <sstream>
#include "vampire.h"
#include "dwarf.h"
#include "floor.h"
#include "treasure.h"

using namespace std;

Dwarf::Dwarf(): Enemy("Dwarf", 100, 100, 20, 30){
	// Assign hp and stuff
	eTreasure = new Treasure(Floor::random(1,2));
	characterSymbol = 'D';
}

string Dwarf::isAttacked(Character *c){
	ostringstream oss;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	heal(-damage);
	oss << "deals " << damage << " damage to " << *this;
	oss << " (" << gethp() << " HP). ";
	// If the attacker is a Vampire, trigger its allergies to do 5 damage
	if(dynamic_cast<Vampire *>(c)) {
		c->heal(-5);
		oss << "PC suffers 5 damage from allergies. ";
	}
	return oss.str();
}
