#include <string>
#include <sstream>
#include "human.h"
#include "goblin.h"
#include "treasure.h"

using namespace std;

Human::Human():Enemy("Human", 140, 140, 20, 20){
	//Assign hp and stuff
	eTreasure = new Treasure(2);
	characterSymbol = 'H';
}

string Human::onDeath(Character *c){
	ostringstream oss;
	oss << *this << " has been slain. ";
	Player *p = dynamic_cast<Player *>(c);
	if(p) {
		// On Death, "drops" 2 piles of gold (Gold is picked up twice to compensate)
		eTreasure->isPickedUp(p);
		eTreasure->isPickedUp(p);
		// Check if the killer is a Goblin
		Goblin *g = dynamic_cast<Goblin *>(p);
		// If the killer is a Goblin, give it an extra 5 gold
		if(g) {
			g->bank(5);
			oss << 5 + 2*eTreasure->getValue();
		} else {
			oss << 2*eTreasure->getValue();
		}
		oss << " gold was looted. ";
	}
	return oss.str();
}
