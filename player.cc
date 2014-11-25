#include <string>
#include <iomanip>
#include "character.h"
#include "player.h"

using namespace std;

Player::Player(){
	characterSymbol = '@';
	moneyCoins = 0;
}

Player::Player(string race, int maxhp, int hp, int atk, int def) : Character(race, maxhp, hp, atk, def){
	characterSymbol = '@';
	moneyCoins = 0;
}

bool Player::onDeath(Character *c){
	// End game and stuff
	return false;
}

int Player::getScore(){
	return moneyCoins;
}

string Player::getRace(){
	return race;
}

int Player::gethp(){
	return hp;
}

int Player::getatk(){
	return atk;
}

int Player::getdef(){
	return def;
}

int Player::getGold(){
	return moneyCoins;
}
