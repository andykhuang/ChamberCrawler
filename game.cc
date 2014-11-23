#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "game.h"
#include "floor.h"
#include "vampire.h"
#include "player.h"

using namespace std;

Game::Game(){
	gamePlayer = NULL;
	gameFloor = NULL;

	// Start at Floor 1
	floorNum = 1;
}

Game::~Game(){
	delete gamePlayer;
	delete gameFloor;
}

bool Game::setGamePlayer(string race){
	if(race == "s" || race == "S"){
		// TODO: make a new shade
		return true;
	} else if(race == "d" || race == "D"){
		// TODO: make a new drow
		return true;
	} else if(race == "v" || race == "V"){
		gamePlayer = new Vampire;
		return true;
	} else if(race == "g" || race == "G"){
		// TODO: make a new goblin
		return true;
	} else if(race == "t" || race == "T"){
		// TODO: make a new Troll
		return true;
	} else {
		// Not a valid class
		return false;
	}
}

bool isValidDirection(string dir){
	if(dir == "no" || dir == "so" || dir == "ea" || dir == "we" || dir == "ne" || dir == "nw" || dir == "se" || dir == "sw"){
		return true;
	}
	return false;
}

// Method for command interpretation
// 	- no, so, ea, we, ne, nw, se, sw : Movement direction
//	- u <direction> : Use in direction given
//	- a <direction> : Attack in direction given
//	- s d v g t specifies the race the player wishes to be when starting a game
//	- r : Restarts the game
//	- q : Quits the game (Still displays the score)
void Game::playGame(){
	// Sentinel Stuff
	bool isRestart = false;
	bool isQuit = false;
	
	// Variable for storing and parsing commands
	string command;	// The First part of the command (ie: u)
	string cOption; // The Second part of the command (ie: direction)

	// Information Fields
	string playerRace;

	// Restart While loop
	while(!isQuit){
		// Read Player Race
		cout << "Choose a race to begin the game: ";
		cin >> command;
		cout << endl;
		if(cin.fail() && command != ""){
			cin.clear();
			cin.ignore();
			continue;
		}

		if(!setGamePlayer(command)){
			cout << "Not a valid race. Please choose again" << endl;
			continue;
		}
		
		// At this point the player has selected a valid race, game will begin	
		else {
			// Initialize board and stuff here
			gameFloor = new Floor(floorNum);
			gameFloor->loadFloor();

			// Output the Board and HUD
			cout << "Board & HUD output" << endl;

			// Begin command parsing
			while(!isQuit && !isRestart){
				cin >> command;

				// USE Command performed
				if(command == "u"){
					cin >> cOption;
					if(!isValidDirection(cOption)){
						cout << "Invalid Direction" << endl;
					} else {
						// Use in direction
						cout << "Use " << cOption << endl; 
					}
				} else if(command == "a"){
					cin >> cOption;
					if(!isValidDirection(cOption)){
						cout << "Invalid Direction" << endl;
					} else {
						// Attack in direction
						cout << "Attack " << cOption << endl;
					}
				} else if(command == "r"){
					// Restart Game
					isRestart = true;
				} else if(command == "q"){
					// Quit Game
					isQuit = true;
				} else {
					// Other wise check if it's a direction
					if(isValidDirection(command)){
						// Move
						cout << "Move " << command << endl;
					} else {
						cout << "Invalid Command" << endl;
					}
				}
			}
			
			// TODO: Free everything that needs freeing here
			// reset all the variables
			isRestart = false;
			command = "";
			cOption = "";
			playerRace = "";
		}

	}
	// End Restart While Loop
}

void Game::descendFloor(){
	floorNum++;

	if(floorNum >= 6){
		// TODO: Trigger game over win condition and tally scores
		
		delete gamePlayer;
		delete gameFloor;
		gamePlayer = NULL;
		gameFloor = NULL;
	}
	else {
		delete gameFloor;
		gameFloor = new Floor(floorNum);
	}
	// delete gameFloor
	// makes a new floor
	// increments the floor lvl
}
