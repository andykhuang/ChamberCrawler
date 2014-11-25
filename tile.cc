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

bool Tile::isSteppedOn(Player *p){
	return true;
}

bool Tile::isSteppedOn(Enemy *e){
	return true;
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
