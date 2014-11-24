#include <string>
#include <iostream>
#include "chamber.h"
#include "tile.h"

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


void Chamber::place(string name){
	return;
}
