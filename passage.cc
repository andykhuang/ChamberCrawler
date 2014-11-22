#include "tile.h"
#include "passage.h"

Passage::Passage(){
	tileSymbol = '#';
}

bool Passage::isOccupied(Enemy *e){
	return true;
}
