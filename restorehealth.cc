#include "potion.h"
#include "restorehealth.h"

using namespace std;

bool RestoreHealth::isUsed(Player *p){
	// Add to player health
	return true;
}

bool RestoreHealth::isUsed(Enemy *e){
	return false;
}
