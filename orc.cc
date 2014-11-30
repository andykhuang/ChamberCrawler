#include "enemy.h"
#include "orc.h"
#include "floor.h"
#include "treasure.h"

using namespace std;

Orc::Orc():Enemy("Orc", 180, 180, 30, 25){
	// Set fields
	eTreasure = new Treasure(Floor::random(1,2));
	characterSymbol = 'O';
}
