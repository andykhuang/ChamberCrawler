#include <string>
#include <sstream>
#include <iomanip>
#include "abstractpotion.h"
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

string Player::isAttacked(Character *c){
	ostringstream oss;
	int miss = rand() % 2;
	if(miss == 1) {
		oss << "missed " << characterSymbol;
	} else {
		int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
		heal(-damage);
		oss << "deals " << damage << " to PC.";
	}
	return oss.str();
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
		return actionDesc;
	}else if(command == "move"){
                // TODO: move player
                if(move(dir)){
                        actionDesc = " moves " + dir;
                }
        } else if(command == "use"){
		actionDesc = use(dir);		
        } else if(command == "attack"){
		actionDesc = attack(dir);
        }
	// Check if an action has been performed
	if(actionDesc != "") {
		actionDesc = "PC " + actionDesc;
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

string Player::attack(string dir){
	// Get the Tile to attack
	Tile *dest = host->getNeighbour(dir);
        return dest->isAttacked(this);
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

Player::~Player(){}
