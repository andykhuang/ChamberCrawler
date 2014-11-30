#include "player.h"
#include "shade.h"

using namespace std;

Shade::Shade(): Player("Shade", 125, 125, 25, 25) {}

int Shade::getScore(){
	// At the end of the game, Shade's score is double its gold
	return moneyCoins*2;
}
