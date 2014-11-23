#include <string>
#include <iostream>
#include "player.h"
#include "vampire.h"

using namespace std;

Vampire::Vampire():Player("Vampire", 99999999, 50, 25, 25){
	// TODO: set max hp to int_max
}

bool Vampire::attack(string dir){
	return true;
}

Player::~Player(){}
