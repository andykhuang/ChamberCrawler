#include "tile.h"
#include "wall.h"

using namespace std;

Wall::Wall(bool isVertical){
	tileSymbol = isVertical ? '|' : '-';
}

bool Wall::isOccupied(Player *p){
	return true;
}

bool Wall::isOccupied(Enemy *e){
	return true;
}
