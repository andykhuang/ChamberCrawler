#include <string>
#include "player.h"
#include "dwarf.h"
#include "floor.h"
#include "treasure.h"

using namespace std;

Dwarf::Dwarf():Enemy("Dwarf", 100, 100, 20, 30){
	// Assign hp and stuff
	eTreasure = new Treasure(Floor::random(1,2));
	characterSymbol = 'F';
}

string Dwarf::isAttacked(Character *c){
	// if c is a orc then suffer double damage
	return "";
}
