#include "enemy.h"
#include "human.h"

using namespace std;

Human::Human(){
	//Assign hp and stuff
	characterSymbol = 'H';
}

bool Human::onDeath(Character *c){
	// forgot special
	return true;
}
