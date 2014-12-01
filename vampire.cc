#include <string>
#include <iostream>
#include "vampire.h"
#include "tile.h"

using namespace std;

// Set maxhp to -1 since Vampire overrides the heal method
// so that it can heal endlessly
Vampire::Vampire(): Player("Vampire", -1, 50, 25, 25){}

void Vampire::heal(int amount){
	// Ensure that the updated hp value is non-negative
	// NOTE: Vampires do not have a "maxhp" so they can gain infinite hp
	if(hp + amount < 0) {
		hp = 0;
	} else {
		hp += amount;
	}
}
