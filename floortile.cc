#include <string>
#include "tile.h"
#include "item.h"
#include "enemy.h"
#include "player.h"
#include "floortile.h"

using namespace std;

FloorTile::FloorTile(){
	tileSymbol = '.';
}

bool FloorTile::isOccupied() {
	return !(character == NULL && item == NULL);
}

string FloorTile::isAttacked(Player *p) {
	// If there is not Character on this Tile, there is nothing to attack
	if(character == NULL) return "";
	// If the Character on this Tile is an Enemy, then attack it
	else if(dynamic_cast<Enemy *>(character)) {
		string response = character->isAttacked(p);
		// Check if the target was slain by the attack
		string deathRattle = character->isSlain(p);
		if(deathRattle != "") {
			// If the target was slain then delete it from this Tile
			delete character;
			character = NULL;
			response += deathRattle;
		}
		// Return a string detailing this attack
		return response;
	} else {
		// If the Character on this Tile is a Player, it cannot be attacked
		return "";
	}

}

string FloorTile::isAttacked(Enemy *e) {
	// If there is not Character on this Tile, there is nothing to attack
	if(character == NULL) return "";
	// If the Character on this Tile is a Player, then attack it
	else if(dynamic_cast<Player *>(character)) {
		// Return a string detailing this attack
		return character->isAttacked(e);
	} else {
		// If the Character on this Tile is an Enemy, it cannot be attacked
		return "";
	}
}

string FloorTile::isUsed(Player *p){
	if(item == NULL) return "";
	if(item->isUsed(p)) {
		string actionDesc = "uses " + item->getName() + ". ";
		// If the item has been used, clear the item from this Tile
		clearTile();
		// Return a string detailing this action
		return actionDesc;
	}
	return "";
}

string FloorTile::isPickedUp(Player *p){
	return "";
}
