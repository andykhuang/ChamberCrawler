#include <string>
#include "tile.h"
#include "enemy.h"
#include "dragon.h"
#include "dragontreasure.h"

using namespace std;

Dragon::Dragon(DragonTreasure *t): Enemy("Dragon", 150, 150, 20, 20) {
	characterSymbol = 'D';
	treasure = t;
}

void Dragon::setTile(Tile *t) {
	// Set the Tile that this Dragon is on
	host = t;
	// Set this Dragon on the tile
	t->placeCharacter(this);
}

bool Dragon::attack(string dir){
	return false;
}

bool Dragon::move(string dir){
	return true;
}

Dragon::~Dragon(){
	host->clearTile();
}
