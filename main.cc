#include <iostream>
#include "game.h"

using namespace std;

int main(){
	cout << "Main Ran" << endl;
	cout << "Creating game" << endl;
	Game *testGame = new Game;
	cout << "Game Created" << endl;
	cout << "Starting Game" << endl;
	testGame->playGame();
	delete testGame;
	cout << "Game Ended" << endl;
}
