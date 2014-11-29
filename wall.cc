#include <string>
#include "tile.h"
#include "wall.h"

using namespace std;

Wall::Wall(bool isVertical){
	tileSymbol = isVertical ? '|' : '-';
}

void Wall::addNeighbour(Tile *t){
	return;
}

bool Wall::isOccupied(Player *p){
	return true;
}

bool Wall::isOccupied(Enemy *e){
	return true;
}

bool Wall::isSteppedOn(Player *p){
	return false;
}

bool Wall::isSteppedOn(Enemy *e){
	return false;
}
