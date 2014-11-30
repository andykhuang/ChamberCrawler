#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include "abstractpotion.h"
#include "emptypotion.h"
#include "character.h"
#include "player.h"
#include "tile.h"
#include "elf.h"

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

string Player::isAttacked(Character *c){
	ostringstream oss;
	int rollRange = dynamic_cast<Elf *>(c) ? 4 : 2;
	int roll = rand() % rollRange;
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	
	if(roll == 0) {
		oss << "missed PC. ";
	} else if(roll == 3) {	// Only possible if the attacker is an Elf
		damage *= 2;
		oss << "hits twice and deals " << damage << " damage to PC. ";
	} else {
		oss << "deals " << damage << " damage to PC. ";
	}

	heal(-damage);
	return oss.str();
}

void Player::flushPot() {
	delete pot;
	pot = new EmptyPotion;
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
		actionDesc = move(dir);
		if(actionDesc == ""){	
			return INVALID_COMMAND;
		} 
        } else if(command == "use"){
		actionDesc = use(dir);
		if(actionDesc == ""){
			return INVALID_COMMAND;
		}
        } else if(command == "attack"){
		actionDesc = attack(dir);
		if(actionDesc == ""){
			return INVALID_COMMAND;
		}
        }
	// Check if an action has been performed
	if(actionDesc != "") {
		actionDesc = "PC " + actionDesc;
		// At the end of an action, activate the Player's hidden power
		actionDesc += " " + hiddenPower();
	}
	return actionDesc;
}

string Player::move(string dir){
	string moveDesc = "";
	int initialGold = getGold();
        // Get tile to step on
	Tile *dest = host->getNeighbour(dir);
	if(dest->isSteppedOn(this)){
		int goldDiff = getGold() - initialGold;
		// Notify the original tile that the character left
		host->clearTile();
		// At this point dest already hosts player so change the tile the player is on
		host = dest;
		// Generate the move description
		moveDesc += "moves " + convertDirection(dir);
		
		// Sentence structure: PC moves dir and sees a (XX) Potion. Picked up Y gold
		// Sees a Potion (can see multiple)
		int numPotsSeen = 0;
		Tile **potTileCheck = dest->getNeighbour();
		for(int i = 0; i < 8; i++){
			string tempPotDesc = "";
			if(potTileCheck[i] != NULL){
				Item *tempItem = potTileCheck[i]->getItemPtr();
				if(tempItem != NULL){
					tempPotDesc = potTileCheck[i]->getItemPtr()->seesPotion();
				}
			}
			
			if(tempPotDesc != ""){
				if(numPotsSeen > 0){
					moveDesc += " and a(n) " + tempPotDesc;
					numPotsSeen++;
				}
				else if(numPotsSeen == 0){
					moveDesc += " and sees a(n) " + tempPotDesc;
					numPotsSeen++;
				}
			}
		}
		
		// Picks up gold
		if(goldDiff > 0){
			ostringstream converter;
			converter << ". Picked up " << goldDiff << " gold";
			moveDesc += converter.str();
		}
		// Return moved
		return moveDesc + ".";
	}
	return "";
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

// Players get no hidden powers by default :(
string Player::hiddenPower() {}

void Player::onDeath(Character *c){
	// End game and stuff
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

// converts shortform to long form or vice versa
string Player::convertDirection(string dir){
	map<string, string>dirMap;
	dirMap["nw"] = "North West";
	dirMap["no"] = "North";
	dirMap["ne"] = "North East";
	dirMap["we"] = "West";
	dirMap["ea"] = "East";
	dirMap["sw"] = "South West";
	dirMap["so"] = "South";
	dirMap["se"] = "South East";
	
	for(map<string, string>::iterator i = dirMap.begin(); i != dirMap.end(); i++){
		if(dir == i->first) return i->second;
		if(dir == i->second) return i->first;
	}
	return "";
}

bool Player::isPlayer(){
	return true;
}

Player::~Player(){}
