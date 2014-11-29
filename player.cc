#include <string>
#include <iomanip>
#include "character.h"
#include "player.h"
#include "tile.h"

using namespace std;

Player::Player(){
	characterSymbol = '@';
	moneyCoins = 0;
}

Player::Player(string race, int maxhp, int hp, int atk, int def) : Character(race, maxhp, hp, atk, def){
	characterSymbol = '@';
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

string Player::performAction(string command, string dir){
        string actionDesc = "";

	if(command == ""){
		return "";
	}

        if(command == "move"){
                // TODO: move player
                if(move(dir)){
                        actionDesc = " moves " + dir;
                }
        } else if(command == "use"){
                // TODO: use in direction if possible
        } else if(command == "attack"){
                // TODO: attack in direction if possible
        } else {
                return actionDesc;
        }

        // Returns an empty string if it can't be done
        return actionDesc;
}


bool Player::move(string dir){
        // Get tile to step on
	Tile *dest = host->getNeighbour(dir);
	if(dest->isSteppedOn(this)){
		// Notify the original tile that the character left
		host->characterLeft();
		// At this point dest already hosts player so change the tile the player is on
		host = dest;
		// Return moved
		return true;
	}
	return false;
}


bool Player::attack(string dir){
        return false;
}


bool Player::pickup(string dir){
        return false;
}

bool Player::use(string dir){
        return false;
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

AbstractPotion *Player::getPotion() {
	return pot;
}

void Player::setPotion(AbstractPotion *ap) {
	pot = ap;
}
