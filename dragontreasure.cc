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

// Used during file parsing to set the host of the DragonTreasure and its Dragon
DragonTreasure::DragonTreasure(Tile *dHost, Tile *tHost):Treasure(6){
	d = new Dragon(this);
	dualSetHost(dHost, tHost);
}

// Clears the Dragon guarding this DragonTreasure allowing it to be picked up
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
		// Randomly choose a neighbouring Tile for the Dragon to occupy
		int ind = Floor::random(0, 7);
		// If the Tile is unoccupied, let the Dragon occupy it
		if(!neighbours[ind]->isOccupied()) {
			d->setTile(neighbours[ind]);
			dragonSet = true;
		}
	}
}

bool DragonTreasure::canBeSteppedOn(Player *p){
	// DragonTreasure can only be stepped on once its Dragon has been slain
	if(d != NULL) return false;
	// If the Dragon has been slain, stepping on the DragonTreasure picks it up
	isPickedUp(p);
	return true;
}

bool DragonTreasure::canBeSteppedOn(Enemy *e){
	return false;
}

bool DragonTreasure::isPickedUp(Player *p){
	// Only pick up the DragonTreasure if the Dragon has been slain
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
