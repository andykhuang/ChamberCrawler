#include <string>
#include "enemy.h"
#include "elf.h"
#include "floor.h"
#include "treasure.h"

using namespace std;

Elf::Elf():Enemy("Elf", 140, 140, 30, 10){
	// Assign hp and stuff
	eTreasure = new Treasure(Floor::random(1,2));
	characterSymbol = 'E';
}
