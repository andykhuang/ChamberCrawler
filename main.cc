#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// Includes the required game files
#include "game.h"

using namespace std;

int main(){
	Game *test = new Game;
	cout << "Game Created" << endl;
	test->playGame();
	delete test;
}
