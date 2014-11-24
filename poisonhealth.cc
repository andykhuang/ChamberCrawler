#include "potion.h"
#include "poisonhealth.h"

using namespace std;

bool PoisonHealth::isUsed(Player *p){
	// TODO: Add the health negatively to the given player p
	// TODO: Can this potion kill?
	return true;
}

bool PoisonHealth::isUsed(Enemy *e){
	return false;
}
