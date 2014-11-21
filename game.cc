#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "game.h"

using namespace std;

Game::Game(){
	// gameFloor = null;
	// gamePlayer = null;
}

Game::~Game(){
	// delete gameFloor;
	// delete gamePlayer;
}

void Game::playGame(){
	cout << "Game Started" << endl;
	cout << "Game Ended" << endl;
}

void Game::setGamePlayer(string startingRace){
	// Create a player with startingRace
}
