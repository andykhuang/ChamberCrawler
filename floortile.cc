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
		return character->isAttacked(p);
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
		return character->isAttacked(e);
	} else {
		// If the Character on this Tile is an Enemy, it cannot be attacked
		return "";
	}
}

string FloorTile::isUsed(Player *p){
	if(item == NULL) return "";
	if(item->isUsed(p)) {
		string actionDesc = "uses " + item->getName();
		// If the item has been used, clear the item from the tile
		clearTile();
		return actionDesc;
	}
	return "";
}

string FloorTile::isPickedUp(Player *p){
	return "";
}

bool FloorTile::performAction(){
	return false;
}
