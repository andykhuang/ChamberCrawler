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
	int miss = rand() % 2;
	if(miss == 1) {
		oss << "missed PC. ";
	} else {
		int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
		// If the attacker is an Orc, take 50% more damage (1.5x rounded up)
		if(dynamic_cast<Orc *>(c)) {
			// To maintain the integer-ness of the damage value
			damage = ((15 * damage) + 9) / 10;		
		}
		// If the attacker is an Elf, roll again for double strike
		if(dynamic_cast<Elf *>(c)) {
			miss = rand() % 2;
			if(miss == 0) {
				damage *= 2;
			}
		}
		heal(-damage);
		oss << "deals " << damage << " to PC. ";
	}
	return oss.str();
}
