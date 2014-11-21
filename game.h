#ifndef ___GAME_H___
#define ___GAME_H___
#include <string>

class Player;
class Floor;

class Game {
	// Private fields
	Player *gamePlayer;
	Floor *gameFloor;

	int floorNum;

	// Private methods
	void setGamePlayer(std::string race);

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
