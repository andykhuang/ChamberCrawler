#include <string>
#include "enemy.h"
#include "dragon.h"
#include "dragontreasure.h"
#include "tile.h"

using namespace std;

Dragon::Dragon(DragonTreasure *dt){
	treasure = dt;
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
