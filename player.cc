#include <string>
#include <iomanip>
#include "abstractpotion.h"
#include "character.h"
#include "player.h"
#include "tile.h"

using namespace std;

const string INVALID_COMMAND = "Invalid Command";

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
		else {
			actionDesc = INVALID_COMMAND;
		}
        } else if(command == "use"){
                // TODO: use in direction if possible
		actionDesc = use(dir);
		if(actionDesc == ""){
			return INVALID_COMMAND;
		}
        } else if(command == "attack"){
                // TODO: attack in direction if possible
        } else {
		// Returns an empty string if no matching command is found
                return actionDesc;
        }

	return actionDesc;
}

bool Player::move(string dir){
        // Get tile to step on
	Tile *dest = host->getNeighbour(dir);
	if(dest->isSteppedOn(this)){
		// Notify the original tile that the character left
		host->clearTile();
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

string Player::pickup(string dir){
	// Get the Tile to pick up
	Tile *dest = host->getNeighbour(dir);
        return dest->isPickedUp(this);
}

string Player::use(string dir){
	// Get the Tile to use
	Tile *dest = host->getNeighbour(dir);
        return dest->isUsed(this);
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
	return atk + pot->getAtk();
}

int Player::getdef(){
	return def + pot->getDef();
}

int Player::getGold(){
	return moneyCoins;
}

AbstractPotion *Player::getPotion() {
	return pot;
}

void Player::setPotion(AbstractPotion *p) {
	pot = p;
}
