#include "potion.h"
#include "player.h"

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
	cout << "GETTING PLAYER POTION" << endl;
	p = pl->getPotion();
	cout << "PLAYER POTION RETREIVED" << endl;
	// Set the Potion the Player currently has to this Potion
	pl->setPotion(this);
	cout << "PLAYER POTION SET" << endl;
	return true;
}

Potion::~Potion(){
	delete p;
}
