#include <cstdlib>
#include <string>
#include <sstream>
#include "abstractpotion.h"
#include "player.h"
#include "drow.h"

using namespace std;

Drow::Drow(): Player("Drow", 150, 150, 25, 15) {}

int Drow::getAtk() {
	// Want to maintain the integer-ness of the atk value
	return atk + ((15 * pot->getAtk()) / 10);
}

int Drow::getDef() {
	// Want to maintain the integer-ness of the def value
	return def + ((15 * pot->getAtk()) / 10);
}

void Drow::heal(int amount) {
	// To maintain the integer-ness of the values
	int effective_amount = (15*amount)/10;
	
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
	if(miss == 1) {
		oss << "missed PC.";
	} else {
		int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
		heal(-damage);
		oss << "deals " << damage << " to PC.";
	}
	return oss.str();
}
