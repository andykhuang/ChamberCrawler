#include "dragontreasure.h"
#include "dragon.h"
#include "tile.h"
#include "floor.h"
#include "player.h"

using namespace std;

DragonTreasure::DragonTreasure():Treasure(/*value*/6){
	// Create a new Dragon and assign it to guard this DragonTreasure
	d = new Dragon(this);
}

DragonTreasure::DragonTreasure(Tile *dHost, Tile *tHost):Treasure(6){
	d = new Dragon(this);
	dualSetHost(dHost, tHost);
}

void DragonTreasure::clearDragon() {
	d = NULL;
}

void DragonTreasure::dualSetHost(Tile *dHost, Tile *tHost){
	host = tHost;
	d->setTile(dHost);
	
}

void DragonTreasure::setHost(Tile *t) {
	// Set the Tile that this DragonTreasure is on
	host = t;
	// Set the Tile that the Dragon guarding this DragonTreasure is on
	bool dragonSet = false;
	Tile **neighbours = t->getNeighbour();
	while(!dragonSet) {
		int ind = Floor::random(0, 7);
		if(!neighbours[ind]->isOccupied()) {
			// TODO: increment the floor's enemy counter
			d->setTile(neighbours[ind]);
			dragonSet = true;
		}
	}
}

bool DragonTreasure::canBeSteppedOn(Player *p){
	// Picks up the gold only if the Dragon guarding it is slain
	if(d != NULL) return false;
	isPickedUp(p);
	return true;
}

bool DragonTreasure::canBeSteppedOn(Enemy *e){
	return false;
}

bool DragonTreasure::isPickedUp(Player *p){
	if(d == NULL) {
		p->bank(value);
		return true;
	} else {
		return false;
	}
}

bool DragonTreasure::isPickedUp(Enemy *e){
	return false;
}
