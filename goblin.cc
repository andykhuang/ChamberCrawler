#include <string>
#include <sstream>
#include "orc.h"
#include "elf.h"
#include "floor.h"
#include "treasure.h"
#include "goblin.h"

using namespace std;

Goblin::Goblin(): Player("Goblin", 110, 110, 15, 20) {}

string Goblin::isAttacked(Character *c){
	ostringstream oss;
	int rollRange = dynamic_cast<Elf *>(c) ? 4 : 2;
	int roll = rand() % rollRange;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);

	if(roll == 0) {
		oss << "missed PC. ";
	} else if(roll == 3) {	// Only possible if the attacker is an Elf
		damage *= 2;
		oss << "hits twice and deals " << " damage to PC. ";
	} else {
		// If the attacker is an Orc, take 50% more damage (1.5x rounded up)
		if(dynamic_cast<Orc *>(c)) {
			// To maintain the integer-ness of the damage value
			damage = ((15 * damage) + 9) / 10;		
		}
		oss << "deals " << damage << " damage to PC. ";
	}

	heal(-damage);
	return oss.str();
}
