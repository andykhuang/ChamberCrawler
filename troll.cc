#include <string>
#include "player.h"
#include "troll.h"

using namespace std;

Troll::Troll(): Player("Troll", 120, 120, 25, 15) {}

void Troll::hiddenPower() {
	// Regains 5 HP
	heal(5);
}
