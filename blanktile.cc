#include <string>
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

// Nothing can step over Blank Tiles
bool BlankTile::isSteppedOn(Player *p){
	return false;
}

bool BlankTile::isSteppedOn(Enemy *e){
	return false;
}
