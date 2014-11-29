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
#include "treasure.h"
#include "dragontreasure.h"

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
			c->setTile(tiles[tileIndex]);
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
		// If this item is a DragonTreasure
		if(dynamic_cast<DragonTreasure *>(i)){
			bool hasDragonSpace = false;
			Tile **neighbourCheck = tiles[tileIndex]->getNeighbour();
			// Check that there's at least one neighbour that is not occupied
			for(int i = 0; i < 8 && !hasDragonSpace; i++){
				if(neighbourCheck[i] != NULL && !neighbourCheck[i]->isOccupied()){
					hasDragonSpace = true;
				}
			}
			if(!hasDragonSpace) return false;
		}
		// Try to place on the tile
		if(tiles[tileIndex]->placeItem(i)){
			i->setHost(tiles[tileIndex]);
			successFlag = true;
			return true;
		}
	}
	return false;
}
