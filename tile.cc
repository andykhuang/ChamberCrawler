#include <iostream>
#include <string>
#include "tile.h"
#include "character.h"
#include "player.h"
#include "item.h"

using namespace std;

Tile::Tile(){
	//TODO: Heap allocate an array of 8 neighbours pointers
	neighbours = NULL;
	item = NULL;
	character = NULL;
	tileSymbol = ' ';
}

Tile::Tile(Character *c){
	neighbours = NULL;
	item = NULL;
	character = c;
	tileSymbol = 'C'; // TODO: get it from the character pointer
}

Tile::Tile(Item *i){
	neighbours = NULL;
	item = i;
	character = NULL;
	tileSymbol = 'i'; // TODO: get it from the item pointer
}

Tile::~Tile(){
	for(int i = 0; i < 8; i++){
		delete neighbours[i];
	}
	delete [] neighbours;
	delete item;
	delete character;
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
	out << "Potato" << endl;
	return out;
}
