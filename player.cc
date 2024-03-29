#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include "abstractpotion.h"
#include "restorehealth.h"
#include "poisonhealth.h"
#include "boostatk.h"
#include "boostdef.h"
#include "woundatk.h"
#include "wounddef.h"
#include "emptypotion.h"
#include "character.h"
#include "player.h"
#include "tile.h"
#include "elf.h"
#include "merchant.h"

using namespace std;

const string INVALID_COMMAND = "Invalid Command";

Player::Player(string race, int maxhp, int hp, int atk, int def) : Character(race, maxhp, hp, atk, def){
	characterSymbol = '@';
	moneyCoins = 0;

	// Reset all Potion encounters and Merchant friendliness
	RestoreHealth::resetEncounters();
	PoisonHealth::resetEncounters();
	BoostAtk::resetEncounters();
	BoostDef::resetEncounters();
	WoundAtk::resetEncounters();
	WoundDef::resetEncounters();

	Merchant::resetFriendliness();
}

string Player::isAttacked(Character *c){
	ostringstream oss;
	// Determine the roll range based on whether the attacker is an Elf
	int rollRange = dynamic_cast<Elf *>(c) ? 4 : 2;
	int roll = rand() % rollRange;
	// Calculate the damage taken from the attack
	int damage = ((100 * c->getatk()) + (100 + def - 1)) / (100 + def);
	
	if(roll == 0) {
		// All enemies have 50% chance to miss the Player
		// NOTE: Elves have a 25% chance to miss both attacks
		oss << "missed PC. ";
	} else if(roll == 3) {	// Only possible if the attacker is an Elf
		// If the Elf lands both attacks, the Player takes double damage
		damage *= 2;
		heal(-damage);
		oss << "hits twice and deals " << damage << " damage to PC. ";
	} else {
		// Only take damage if the attack succeeds
		heal(-damage);
		oss << "deals " << damage << " damage to PC. ";
	}

	// Return a string detailing this attack
	return oss.str();
}

// Called at the end of every floor to remove the Player's buffs
void Player::flushPot() {
	delete pot;
	pot = new EmptyPotion;
}

void Player::bank(int amount) {
	// Ensure the updated value for moneyCoins is non-negative
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
		actionDesc += hiddenPower();
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
		return moveDesc + ". ";
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
string Player::hiddenPower() {
	return "";
}

string Player::onDeath(Character *c){
	ostringstream oss;
	oss << "PC has been slain by " << c << ". ";
	return oss.str();	
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

// Converts short form to long form for directions or vice versa
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
