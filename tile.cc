#include <iostream>
#include <string>
#include "tile.h"
#include "character.h"
#include "player.h"
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

char Tile::getTileSymbol(){
	return tileSymbol;
}

bool Tile::isOccupied(Player *p){
	return true;
}

bool Tile::isOccupied(Enemy *e){
	return true;
}

bool Tile::placeCharacter(Character *c){
	return true;
}

bool Tile::placeItem(Item *i){
	return true;
}

bool Tile::isSteppedOn(Player *p){
	return true;
}

bool Tile::isSteppedOn(Enemy *e){
	return true;
}

ostream &operator<<(ostream &out, const Tile &t){
	// TODO: If an item or charcter exists print that
	if(t.character != NULL){
		out << "@";
	} else if (t.item != NULL){
		out << t.item;
	} else {
	// Otherwise
		out << t.tileSymbol;
	}
	return out;
}
