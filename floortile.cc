#include "tile.h"
#include "floortile.h"

using namespace std;

FloorTile::FloorTile(){
	tileSymbol = '.';
}

bool FloorTile::isUsed(Character *c){
	return false;
}

bool FloorTile::isPickedUp(Character *c){
	return false;
}

bool FloorTile::performAction(){
	return false;
}

void FloorTile::clearTile(){
	// delete and set stuff to null
	return;
}
