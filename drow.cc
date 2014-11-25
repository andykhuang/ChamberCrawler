#include <string>
#include "player.h"
#include "drow.h"

using namespace std;

Drow::Drow(){
	// Assign hp and stuff
}

// No longer necessary to implement this in Drow?
//bool Drow::use(string dir){
//	// Double potion effect here
//	return true;
//}

void heal(int amount) {
	// To maintain the integer-ness of the values
	int effective_amount = (15*amount)/10;
	
	if(hp + effective_amount > maxhp) {
		hp = maxhp;
	} else if(hp + effective_amount < 0) {
		hp = 0;
	} else {
		hp += effective_about;
	}
}
