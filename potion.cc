#include "player.h"
#include "enemy.h"
#include "abstractpotion.h"
#include "potion.h"

using namespace std;

Potion::Potion(AbstractPotion *p):p(p){}

int Potion::getAtk() {
	return p->getAtk();
}

int Potion::getDef() {
	return p->getDef();
}

bool Potion::isConsumed(Player *pl) {
	// Wrap this Potion around the Potion the Player currently has
	p = pl->getPotion();
	// Set the Potion the Player currently has to this Potion
	pl->setPotion(this);
	return true;
}

Potion::~Potion(){
	delete p;
}
