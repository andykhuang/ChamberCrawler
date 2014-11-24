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
