#include <string>
#include <iostream>
#include "chamber.h"
#include "tile.h"
#include "character.h"
#include "player.h"
#include "item.h"

using namespace std;

Chamber::Chamber(Tile **tiles, int size):size(size){
	this->tiles = new Tile *[size];
	//Assign the tiles pointer
	for(int i = 0; i < size; i++){
		this->tiles[i] = tiles[i];
	}
}

Chamber::~Chamber(){
	/*for(int i = 0; i < size; i++){
		delete tiles[i];
		tiles[i] = NULL;
	}*/
	delete [] tiles;
	tiles = NULL;
}
bool Chamber::place(Stairs *s){
	// TODO: place it on random tile
	return true;
}

bool Chamber::place(Character *c){
	// TODO: place it on a random tile
	return true;
}

bool Chamber::place(Item *i){
	// TODO: Place it on a random tile
	return true;
}
