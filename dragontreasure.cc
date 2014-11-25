#include "dragontreasure.h"
#include "treasure.h"
#include "tile.h"

using namespace std;

DragonTreasure::DragonTreasure():Treasure(/*value*/6) {
	// Create a new Dragon and assign it to guard this DragonTreasure
	d = new Dragon(this);
}

DragonTreasure::~DragonTreasure() {
	delete d;
}

void DragonTreasure::clearDragon() {
	delete d;
	d = null;
}

void DragonTreasure::setHost(Tile *t) {
	// Set the Tile that this DragonTreasure is on
	host = t;
	// Set the Tile that the Dragon guarding this DragonTreasure is on
	bool dragonSet = false;
	Tile **neighbours = t.getNeighbours();
	while(!dragonSet) {
		int ind = return (rand() % (8));
		if(!neighbours[ind].isOccupied()) {
			d->setTile(neighbours[ind]);
			dragonSet = true;
		}
	}
}

bool DragonTreasure::isPickedUp(Player *p) {
	// TODO: Logic
	return false;
}

bool DragonTreasure::isPickedUp(Enemy *e) {
	return false;
}
