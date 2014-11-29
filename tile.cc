#include <iostream>
#include <string>
#include "tile.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "enemy.h"

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

Tile::Tile(Character *c){
	item = NULL;
	character = c;
	tileSymbol = 'C'; // TODO: get it from the character pointer
}

Tile::Tile(Item *i){
	item = i;
	character = NULL;
	tileSymbol = 'i'; // TODO: get it from the item pointer
}

void Tile::addNeighbour(Tile *neighbour){
	// Safety
	if(numNeighbours >= MAX_NEIGHBOURS) return;
	
	neighbours[numNeighbours] = neighbour;
	numNeighbours++;
}

Tile *Tile::getNeighbour(string dir){
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
	if(item != NULL) return true;
	if(character != NULL) return true;
	return false;
}

bool Tile::isOccupied(Player *p){
	return true;
}

bool Tile::isOccupied(Enemy *e){
	return true;
}

bool Tile::placeCharacter(Character *c){
	if(!isOccupied()){
		character = c;
		return true;
	}
	// Placement failed
	return false;
}

bool Tile::placeItem(Item *i){
	if(!isOccupied()){
		item = i;
		return true;
	}
	return false;
}

// Can a Player step on this tile?
bool Tile::isSteppedOn(Player *p){
	// You can never step on characters
	if(character != NULL) return false;
	else if(item != NULL){
		// TODO: Do step mechanics
		// Call can step on item or something
		// 	GOLD can be stepped on and will be picked up
		//	STAIRS can be stepped on and will advance the floor
		// 	Otherwise should return false

		if(item->canBeSteppedOn(p)){
			//TODO: Take the gold
			cout << "Gold taken" << endl;
			// Delete the gold
		} 
		// Item can't be stepped on
		else {
			return false;
		}
		
	}
	// If it has no Character and no item then set this tile to have the Player p
	character = p;
	return true;
}

bool Tile::isSteppedOn(Enemy *e){
	if(character != NULL) return false;
	// Unlike players enemies can't step on items either
	else if(item != NULL) return false;

	// Otherwise you can move to here
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
	item = NULL;
	character = NULL;
}

Character *Tile::getCharacterPtr(){
	return character;
}

void Tile::removeTreasure() {
	delete item;
	item = NULL;
}

// Virtual Tile Destructor implementation
Tile::~Tile(){
	// A Tile should not delete its neighbours as that is handled by the floor
	delete item;
	item = NULL;
	delete character;
	character = NULL;
}

ostream &operator<<(ostream &out, const Tile &t){
	// TODO: If an item or charcter exists print that
	if(t.character != NULL){
		out << *(t.character);
	} else if (t.item != NULL){
		out << *(t.item);
	} else {
	// Otherwise
		out << t.tileSymbol;
	}
	return out;
}
