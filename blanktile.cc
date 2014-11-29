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

// Blank Tiles are always occupied
bool BlankTile::isOccupied(Player *p){
	return true;
}

bool BlankTile::isOccupied(Enemy *e){
	return true;
}

// Nothing can step over Blank Tiles
bool BlankTile::isSteppedOn(Player *p){
	return false;
}

bool BlankTile::isSteppedOn(Enemy *e){
	return false;
}

// Nothing can attack Blank Tiles
string BlankTile::isAttacked(Player *p){
	return "";
}

string BlankTile::isAttacked(Enemy *e){
	return "";
}
