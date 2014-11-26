#include "item.h"
#include "abstractpotion.h"
#include "player.h"
#include "enemy.h"

using namespace std;

AbstractPotion::AbstractPotion() {
	itemSymbol = 'P';
}

AbstractPotion::~AbstractPotion() {}
