#include <string>
#include "halfling.h"
#include "enemy.h"
#include "treasure.h"
#include "floor.h"

using namespace std;

Halfling::Halfling():Enemy("Halfling", 100, 100, 15, 20){
	eTreasure = new Treasure(Floor::random(1,2));
	characterSymbol = 'L';
}

string Halfling::isAttacked(Character *p){
	return "";
}
