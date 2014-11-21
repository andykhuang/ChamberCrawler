#ifndef ___GAME_H___
#define ___GAME_H___

// class Floor;
// class Player;

class Game{
	// Floor *gameFloor;
	// Player *gamePlayer;
	public:
		Game();
		~Game();
		void playGame();
		void setGamePlayer(std::string startingRace);
};
#endif
