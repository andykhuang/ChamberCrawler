#include <string>
#include "character.h"
#include "enemy.h"
#include "treasure.h"

using namespace std;

bool Enemy::onDeath(Character *c){
	return true;
}

string Enemy::performAction(string command, string dir){
	return "Enemy perform Action";
}


Enemy::Enemy(){
	t = NULL;
}
Enemy::~Enemy(){
	delete t;
}
