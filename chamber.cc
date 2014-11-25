#include <string>
#include <iostream>
#include "chamber.h"
#include "tile.h"
#include "character.h"
#include "player.h"
#include "item.h"
#include "floor.h"
#include "stairs.h"
#include "floortile.h"

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

bool Chamber::isFull(){
	for(int i = 0; i < size; i++){
		if(!tiles[i]->isOccupied()) return false;
	}
	return true;
}

bool Chamber::place(Stairs *s){
	int successFlag = false;
	
	if(isFull()) return false;

	while(!successFlag){
		int tileIndex = Floor::random(0, size-1);
		// If nothing on the tile (should never be anything on tile)
		if(tiles[tileIndex]->placeItem(s)){
			s->setHost(tiles[tileIndex]);
			successFlag = true;
			return true;
		}
	}
	return false;
}

bool Chamber::place(Character *c){
	// TODO: place it on a random tile
	int successFlag = false;
	
	if(isFull()) return false;	

	while(!successFlag){
		int tileIndex = Floor::random(0, size-1);
		if(tiles[tileIndex]->placeCharacter(c)){
			successFlag = true;
			return true;
		}
	}
	return false;
}

bool Chamber::place(Item *i){
	// TODO: Place it on a random tile
	int successFlag = false;
	
	if(isFull()) return false;

	while(!successFlag){
		int tileIndex = Floor::random(0, size-1);
		// Try to place on the tile

		// Testing purposes only!!!!
		if(!tiles[tileIndex]->isOccupied()) tiles[tileIndex]->setTileSymbol('P');
		// REMOVE THE ABOVE LINE WHEN POTION IS DONE IMPLEMENTATION
		
		successFlag = true;
		return true;
	}
	return false;
}
