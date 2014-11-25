#include "blanktile.h"
#include "tile.h"
#include "item.h"
#include "character.h"

using namespace std;

void BlankTile::addNeighbour(Tile *t){
	return;
}

bool BlankTile::isOccupied(Player *p){
	return true;
}

bool BlankTile::isOccupied(Enemy *e){
	return true;
}

// Virtual Tile Destructor implementation
Tile::~Tile(){
	// A Tile should not delete its neighbours as that is handled by the floor
	delete item;
	item = NULL;
	character = NULL;
}
