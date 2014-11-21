#include "tile.h"
#include "wall.h"

using namespace std;

Wall::Wall(bool isVertical){
	tileSymbol = isVertical ? '|' : '-';
}

Wall::isOccupied(Character *c){
	return true;
}

Wall::isOccupied(Enemy *e){
	return true;
}
