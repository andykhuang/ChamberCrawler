#include "character.h"
#include "player.h"

using namespace std;

bool Player::onDeath(Character *c){
	return false;
}

void Player::move(int dir){
	return;
}

bool Player::isDead(){
	return hp <= 0;
}

void Player::use(int dir){
	return;
}

void Player::pickup(int dir){
	return;
}
