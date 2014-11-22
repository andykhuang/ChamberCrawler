#include "character.h"
#include "player.h"

using namespace std;

bool Player::onDeath(Character *c){
	// End game and stuff
	return false;
}

int Player::getScore(){
	return moneyCoins;
}
