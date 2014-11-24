#ifndef ___GAME_H___
#define ___GAME_H___
#include <string>
#include "player.h"
#include "floor.h"

class Game {
	// Private fields
	Player *gamePlayer;
	Floor *gameFloor;

	int floorNum;

	// Private methods
	bool setGamePlayer(std::string race);
	void displayHUD(std::string action = "");

	public:
	// Constructor
	Game();

	// Parses user commands
	void playGame();

	// Is called when the player reaches the stairs on a Floor
	// Generate a new floor or terminate the game depending on the floorNum
	void descendFloor();

	// Destructor
	~Game();
};
#endif
