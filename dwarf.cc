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
	// TODO: Change this back to 'D'
	characterSymbol = 'F';
}

string Dwarf::isAttacked(Character *c){
	ostringstream oss;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	heal(-damage);
	oss << "deals " << damage << " to " << characterSymbol;
	oss << " (" << gethp() << " HP).";
	// If the attacker is a Vampire, trigger its allergies to do 10 damage
	if(dynamic_cast<Vampire *>(c)) {
		c->heal(-10);
	}
	return oss.str();
}
