#include <iostream>
#include <string>
#include "tile.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "item.h"

using namespace std;

Tile::Tile(){
	numNeighbours = 0;
	for(int i = 0; i < MAX_NEIGHBOURS; i++){
		neighbours[i] = NULL;
	}
	
	item = NULL;
	character = NULL;
	tileSymbol = ' ';
}

void Tile::addNeighbour(Tile *neighbour){
	// Safety.
	if(numNeighbours >= MAX_NEIGHBOURS) return;
	
	neighbours[numNeighbours] = neighbour;
	numNeighbours++;
}

Tile *Tile::getNeighbour(string dir){
	// Parses the direction commands and returns the appropriate neighbour
	if(dir == "nw") return neighbours[0];
	else if(dir == "no") return neighbours[1];
	else if(dir == "ne") return neighbours[2];
	else if(dir == "we") return neighbours[3];
	else if(dir == "ea") return neighbours[4];
	else if(dir == "sw") return neighbours[5];
	else if(dir == "so") return neighbours[6];
	else if(dir == "se") return neighbours[7];
	else return NULL;
}


Tile **Tile::getNeighbour(){
	return neighbours;
}

char Tile::getTileSymbol(){
	return tileSymbol;
}

bool Tile::isOccupied(){
	return true;
}

bool Tile::placeCharacter(Character *c){
	// Check if the Tile is occupied
	// If false, place the specified Character onto it and return true
	if(!isOccupied()){
		character = c;
		return true;
	}
	// Otherwise return false
	return false;
}

bool Tile::placeItem(Item *i){
	// Check if the Tile is occupied
	// If false, place the specified Item onto it and return true
	if(!isOccupied()){
		item = i;
		return true;
	}
	// Otherwise return false
	return false;
}

// Can a Player step on this tile?
bool Tile::isSteppedOn(Player *p){
	// You can never step on characters
	if(character != NULL) return false;
	else if(item != NULL){
		// Call canBeSteppedOn to check if the Item can be stepped on
		// 	GOLD can be stepped on and will be picked up
		//	STAIRS can be stepped on and will advance the floor
		// 	Otherwise should return false
		if(item->canBeSteppedOn(p)){
			delete item;
			item = NULL;
		} 
		else {	// Item can't be stepped on
			return false;
		}
		
	}
	// If it has no Character and no item then set this tile to have the Player p
	// or if the item can be stepped on
	character = p;
	return true;
}

bool Tile::isSteppedOn(Enemy *e){
	// If the Tile contains a Character, return false
	if(character != NULL) return false;
	// If the Tile contains an Item, return false (Enemy can't step on Items)
	else if(item != NULL) return false;

	// Otherwise move the specified Enemy onto this Tile and return true
	character = e;
	return true;
}

string Tile::isAttacked(Player *p) {
	return "";
}

string Tile::isAttacked(Enemy *e) {
	return "";
}

string Tile::isUsed(Player *p) {
	return "";
}

string Tile::isPickedUp(Player *p) {
	return "";
}

void Tile::clearTile() {
	// Clears the Tile of occupants by setting the pointers to NULL
	// NOTE: This does not delete the occupants from memory
	item = NULL;
	character = NULL;
}

Character *Tile::getCharacterPtr(){
	return character;
}

Item *Tile::getItemPtr(){
	return item;
}

void Tile::removeTreasure() {
	delete item;
	item = NULL;
}

// Virtual Tile Destructor implementation
Tile::~Tile(){
	// A Tile should not delete its neighbours as that is handled by Floor

	// Delete the Item that is occupying this Tile
	delete item;
	item = NULL;

	// Delete the Character that is occupying this Tile if it's not a Player
	if(character != NULL && !character->isPlayer()){
		delete character;
	}
	character = NULL;
}

ostream &operator<<(ostream &out, const Tile &t){
	// If the Tile has an occupant, ouput the occupant
	if(t.character != NULL){
		out << *(t.character);
	} else if (t.item != NULL){
		out << *(t.item);
	} else {
	// Otherwise output the tileSymbol
		out << t.tileSymbol;
	}
	return out;
}
