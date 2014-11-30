#include <string>
#include <sstream>
#include "orc.h"
#include "floor.h"
#include "treasure.h"
#include "goblin.h"

using namespace std;

Goblin::Goblin(): Player("Goblin", 110, 110, 15, 20) {}

string Goblin::isAttacked(Character *c){
	ostringstream oss;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	heal(-damage);
	oss << "deals " << damage << " to " << characterSymbol << ".";
	// If the attacker is an Orc, take 50% more damage
	if(dynamic_cast<Orc *>(c)) {
		heal(-((damage + 1)/2));		
	}
	return oss.str();
}
