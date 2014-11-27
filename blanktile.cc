#include <iostream>
#include "blanktile.h"
#include "tile.h"
#include "item.h"
#include "character.h"
#include "enemy.h"

using namespace std;

void BlankTile::addNeighbour(Tile *t){
	return;
}

// Blank tiles are always occupied
bool BlankTile::isOccupied(Player *p){
	return true;
}

bool BlankTile::isOccupied(Enemy *e){
	return true;
}


// Nothing can step over blank tiles
bool BlankTile::isSteppedOn(Player *p){
	return false;
}

bool BlankTile::isSteppedOn(Enemy *e){
	return false;
}
// Virtual Tile Destructor implementation
Tile::~Tile(){
	// A Tile should not delete its neighbours as that is handled by the floor
	delete item;
	item = NULL;
	delete character;
	character = NULL;
}
