#include "enemy.h"
#include "human.h"
#include "treasure.h"

using namespace std;

Human::Human():Enemy("Human", 140, 140, 20, 20){
	//Assign hp and stuff
	eTreasure = new Treasure(4);
	characterSymbol = 'H';
}

bool Human::onDeath(Character *c){
	// forgot special
	return true;
}
