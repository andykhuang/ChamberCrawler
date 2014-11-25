#ifndef ___GAME_H___
#define ___GAME_H___
#include <string>
#include "player.h"
#include "floor.h"

class Game {
	public:
		static Game *getInstance();
		static void cleanup();

		// Parses user commands
		void playGame();

		// Is called when the player reaches the stairs on a Floor
		// Generate a new floor or terminate the game depending on the floorNum
		void descendFloor();

	
	private:
		// Pointer to the only instance of the game
		static Game *instance;
		// Private fields
		Player *gamePlayer;
		Floor *gameFloor;

		int floorNum;
		
		// Constructor
		Game();
		
		// Destructor
		~Game();

		// Private methods
		bool setGamePlayer(std::string race);
		void displayHUD(std::string action = "");

};
#endif
