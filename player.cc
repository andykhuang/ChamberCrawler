#include <string>
#include <iomanip>
#include "abstractpotion.h"
#include "character.h"
#include "player.h"

using namespace std;

Player::Player(){
	moneyCoins = 0;
}

Player::Player(string race, int maxhp, int hp, int atk, int def) : Character(race, maxhp, hp, atk, def){
	moneyCoins = 0;
}

void Player::heal(int amount) {
	if(hp + amount > maxhp) {
		hp = maxhp;
	} else if(hp + amount < 0) {
		hp = 0;
	} else {
		hp += amount;
	}
}

void Player::bank(int amount) {
	if(moneyCoins + amount < 0) {
		moneyCoins = 0;
	} else {
		moneyCoins += amount;
	}
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
	return atk + potion->getAtk();
}

int Player::getdef(){
	return def + potion->getDef();
}

int Player::getGold(){
	return moneyCoins;
}

AbstractPotion *Player::getPotion() {
	return pot;
}

void Player::setPotion(AbstractPotion *ap) {
	pot = ap;
}
