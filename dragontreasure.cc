#include "dragontreasure.h"
#include "treasure.h"

using namespace std;

DragonTreasure::DragonTreasure():Treasure(/*value*/7){
	// d = new Dragon();
}

DragonTreasure::~DragonTreasure(){
	// delete the d;
}

bool DragonTreasure::isPickedUp(Player *p){
	// TODO: Logic
	return false;
}

bool DragonTreasure::isPickedUp(Enemy *e){
	return false;
}
