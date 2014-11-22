#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "game.h"
#include "floor.h"
#include "player.h"

using namespace std;

Game::Game(){
	gamePlayer = NULL;
	gameFloor = NULL;

	// Start at Floor 1
	floorNum = 1;
}

Game::~Game(){
	//delete gamePlayer;
	delete gameFloor;
}

void Game::playGame(){
	cout << "Potato" << endl;
}

void Game::descendFloor(){
	// delete gameFloor
	// makes a new floor
	// increments the floor lvl
}
