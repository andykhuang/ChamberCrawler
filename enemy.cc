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

bool Enemy::move(string dir){
        // First can I move in direction?


        // That tile should host me now

        // The tile i'm on shouldn't have me

        // Get tile to step on
        //return t->getNeighbour(dir)->isSteppedOn(this);
	return false;
}


bool Enemy::attack(string dir){
	// TODO: Attack action
        return false;
}

// Enemy cannot pick up things
bool Enemy::pickup(string dir){
        return false;
}


// Enemy cannot use things
bool Enemy::use(string dir){
        return false;
}

Enemy::Enemy() {
	t = NULL;
}

Enemy::Enemy(string race, int maxhp, int hp, int atk, int def): Character(race, maxhp, hp, atk, def) {
	t = NULL;
}
Enemy::~Enemy(){
	delete t;
}
