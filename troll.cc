#include <string>
#include "player.h"
#include "troll.h"

using namespace std;

Troll::Troll(): Player("Troll", 120, 120, 25, 15) {}

string Troll::hiddenPower() {
	// Regains 5 HP if not at max
	if(hp < maxhp) {
		heal(5);
		return "PC heals 5 HP. ";
	} else {
		return "";
	}
}
