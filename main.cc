#include <iostream>
#include <string>
#include "game.h"

using namespace std;

int main(int argc, char *argv[]){
	cout << "Creating game" << endl;
	Game *testGame = Game::getInstance();

	// Check for command line arguments
	if(argc == 2){
		testGame->setFloorFile(argv[1]);
	}
	cout << "Starting Game" << endl;
	testGame->playGame();
	cout << "Game Ended" << endl;
}
