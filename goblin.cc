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
	// Determine the roll range based on whether the attacker is an Elf
	int rollRange = dynamic_cast<Elf *>(c) ? 4 : 2;
	int roll = rand() % rollRange;
	// Calculate the damage of a single hit from the attacker
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);

	if(roll == 0) {
		// 50% chance for any attacker to miss
		// Since Elves attack twice (they have a 25% chance to miss twice)
		oss << "missed PC. ";
	} else if(roll == 3) {	// Only possible if the attacker is an Elf
		// 25% chance for Elves to hit twice (deal double damage)
		damage *= 2;
		heal(-damage);
		oss << "hits twice and deals " << " damage to PC. ";
	} else {
		// If the attacker is an Orc, take 50% more damage (1.5x rounded up)
		if(dynamic_cast<Orc *>(c)) {
			// To maintain the integer-ness of the damage value
			damage = ((15 * damage) + 9) / 10;		
		}
		heal(-damage);	
		oss << "deals " << damage << " damage to PC. ";
	}

	// Return a string detailing this attack
	return oss.str();
}
