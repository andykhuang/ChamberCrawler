#include <iostream>
#include "game.h"

using namespace std;

int main(){
	cout << "Main Ran" << endl;
	cout << "Creating game" << endl;
	Game *testGame = Game::getInstance();
	cout << "Game Created" << endl;
	cout << "Starting Game" << endl;
	testGame->playGame();
	cout << "Game Ended" << endl;
}
