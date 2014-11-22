#include "tile.h"
#include "doorway.h"

using namespace std;

Doorway::Doorway(){
	tileSymbol = '+';
}

bool Doorway::isOccupied(Enemy *c){
	return true;
}
