#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include "game.h"
#include "floor.h"
#include "stairs.h"
#include "vampire.h"
#include "player.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
#include "merchant.h"

using namespace std;

const string INVALID_COMMAND = "Invalid Command";
bool toNextFloor = false;
bool isQuit = false;
bool isWin = false;
Game *Game::instance = NULL;


// Get the instance of the game
Game* Game::getInstance(){
	if(!instance){
		instance = new Game();
		atexit(cleanup);
	}
	return instance;
}


// Cleans up the game
void Game::cleanup(){
	delete instance;
}


// Game Ctor
Game::Game(){
	gamePlayer = NULL;
	gameFloor = NULL;
	fiveFloorFile = "";

	// Start at Floor 1
	floorNum = 1;
}


// Game dtor
Game::~Game(){
	delete gamePlayer;
	delete gameFloor;

	gamePlayer = NULL;
	gameFloor = NULL;
}


// Display the HUD (player information with the given action)
void Game::displayHUD(string action){
	cout << "Race: " << gamePlayer->getRace() << " ";
	cout << "Gold: " << setw(48) << left << gamePlayer->getGold();
	cout << "Floor: " << floorNum << endl;
	
	cout << setw(5) << left << "HP: " << gamePlayer->gethp() << endl;
	cout << setw(5) << left << "Atk: " << gamePlayer->getatk() << endl;
	cout << setw(5) << left << "Def: " << gamePlayer->getdef() << endl;
	cout << "Action: " << action << endl;
}


// Set the file that contains all 5 floor preloaded layouts if there exists one
void Game::setFloorFile(string fName){
	fiveFloorFile = fName;
}


// Sets the Race of the player
bool Game::setGamePlayer(string race){
	if(race == "s" || race == "S"){
		gamePlayer = new Shade;
		return true;
	} else if(race == "d" || race == "D"){
		gamePlayer = new Drow;
		return true;
	} else if(race == "v" || race == "V"){
		gamePlayer = new Vampire;
		return true;
	} else if(race == "g" || race == "G"){
		gamePlayer = new Goblin;
		return true;
	} else if(race == "t" || race == "T"){
		gamePlayer = new Troll;
		return true;
	} else {
		// Not a valid class
		return false;
	}
}


// Check if the given direction is valid
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
	
	// Variable for storing and parsing commands
	string command;	// The First part of the command (ie: u)
	string cOption; // The Second part of the command (ie: direction)

	// Information Fields
	string playerRace;

	// Restart While loop
	while(!isQuit && !cin.eof()){
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
			// Response messages from the game
			string response = "Player Character has spawned.";

			bool isDead = false;

			// Determines if the issued player command is valid first
			bool isValidCommand = false;
			// Initialize the floor
			// Make a Stair for this floor
			Stairs *tempStair = new Stairs(getInstance());
			gameFloor = new Floor(floorNum);
			
			if(fiveFloorFile == ""){
				gameFloor->loadFloor(gamePlayer, tempStair);
			} else {
				gameFloor->loadPreLoadedFloor(gamePlayer, tempStair, fiveFloorFile);
			}

			// Output the Board and HUD
			cout << *gameFloor << endl;
			displayHUD(response);
			
			// Begin command parsing
			while(!isQuit && !isRestart && !isDead && !cin.eof()){
				cout << "Command: ";
				cin >> command;
				// USE Command performed
				if(command == "u"){
					cin >> cOption;

					if(!isValidDirection(cOption)){
						cout << INVALID_COMMAND << endl;
					} else {
						// Use in direction
						response = gamePlayer->performAction("use", cOption);
						if(response != INVALID_COMMAND){
							isValidCommand = true;
						}
					}
				} else if(command == "a"){
					cin >> cOption;
					if(!isValidDirection(cOption)){
						cout << "Invalid Direction" << endl;
					} else {
						// Attack in direction
						response = gamePlayer->performAction("attack",cOption);
						if(response != INVALID_COMMAND){
							isValidCommand = true;
						}
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
						response = gamePlayer->performAction("move", command);
						// If the command is valid
						if(response != INVALID_COMMAND){
							isValidCommand = true;
						}
					} else {
						cout << "Invalid Command" << endl;
					}
				}
				
				// If the player are to move to the next floor
				if(toNextFloor){
					// Delete the current floor
					delete gameFloor;
					gameFloor = NULL;

					//Clear the potion bonuses
					gamePlayer->flushPot();
					
					// Make new stairs because the old one was deleted
					tempStair = new Stairs(getInstance());

					// Construct the new floor
					gameFloor = new Floor(floorNum);
					
					// Load the floor
					if(fiveFloorFile == ""){
						gameFloor->loadFloor(gamePlayer, tempStair);
					} else {
						gameFloor->loadPreLoadedFloor(gamePlayer, tempStair, fiveFloorFile);
					}
				}
				// Enemy Perform action
				// Display the board and information
				if(!isRestart && !isQuit && isValidCommand){
					if(!toNextFloor){
						response += gameFloor->enemyAction(gamePlayer);
					} else {
						toNextFloor = false;
					}
					cout << *gameFloor << endl;
					displayHUD(response);
					isValidCommand = false;
					isDead = gamePlayer->gethp() <= 0;
				}
				
				// If you died display message and prompt restart
				if(isDead){
					cout << endl;
					cout << "You died" << endl;
					displayScore();
					cout << "Restart? (y/n)" << endl;
					
					while(cin >> command){
						if(command == "y"){
							isRestart = true;
							isQuit = false;
							break;
						}
						else if(command == "n"){
							isQuit = true;
							break;
						}
					}
				}
				
				// If you won display congrats and prompt restart
				if(isWin){
					cout << endl;
					cout << "Congratulations! You WON!" << endl;
					displayScore();
					cout << "Do you want to play again? (y/n)" << endl;
					
					while(cin >> command){
						if(command == "y"){
							isRestart = true;
							isQuit = false;
							break;
						}
						else if(command == "n"){
							isQuit = true;
							break;
						}
					}
				}
				
			}

			// Cleans up the variables for next floor/restart			
			delete gameFloor;
			delete gamePlayer;
			gamePlayer = NULL;
			gameFloor = NULL;
		
			// reset all the variables
			isWin = false;
			isRestart = false;
			command = "";
			cOption = "";
			playerRace = "";
			floorNum = 1;
		}

	}
	// End Restart While Loop
}


// Displays the score the player earned
void Game::displayScore(){
	cout << setfill('-') << setw(20) << "" << endl;
	cout << "     " <<"Score: " << gamePlayer->getScore() << endl;
	cout << setfill('-') << setw(20) << "";
	cout << setfill(' ') << "" << endl;
}

// Go to the next floor
void Game::descendFloor(){
	floorNum++;
	
	// Reached the end of floor 5
	if(floorNum >= 6){
		isWin = true;
		isQuit = true;
	}
	else {
		toNextFloor = true;
	}
}
