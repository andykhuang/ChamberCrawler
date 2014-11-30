#include <string>
#include "tile.h"
#include "goblin.h"
#include "dragon.h"
#include "dragontreasure.h"

using namespace std;

Dragon::Dragon(DragonTreasure *t): Enemy("Dragon", 150, 150, 20, 20) {
	characterSymbol = 'D';
	treasure = t;
}

void Dragon::onDeath(Character *c) {
	treasure->clearDragon();
	// Check if the killer is a Goblin
	Goblin *g = dynamic_cast<Goblin *>(c);
	// If the killer is a Goblin, give it an extra 5 gold
	if(g) {
		g->bank(5);
	}
}

void Dragon::setTile(Tile *t) {
	// Set the Tile that this Dragon is on
	host = t;
	// Set this Dragon on the tile
	t->placeCharacter(this);
}

string Dragon::attack(){
	string actionDesc = "";
	Tile **neighbours = host->getNeighbour();
	// Try to attack every Tile around this Dragon until one succeeds
	// or there are no more Tiles to attack
	for(int i = 0; i < 8 && actionDesc == ""; i++) {
		actionDesc = neighbours[i]->isAttacked(this);
	}
	// If there is nothing to attack around the Dragon
	// Try to attack everything around the DragonTreasure
	if(actionDesc == "") {
		neighbours = (treasure->host)->getNeighbour();
		// Try to attack every Tile around this Dragon until one succeeds
		// or there are no more Tiles to attack
		for(int i = 0; i < 8 && actionDesc == ""; i++) {
			actionDesc = neighbours[i]->isAttacked(this);
		}
	}
	return actionDesc;
}

string Dragon::move(string dir){
	return "Moved";
}
