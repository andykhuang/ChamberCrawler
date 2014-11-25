#ifndef ___EMPTYPOTION_H___
#define ___EMPTYPOTION_H___
#include "abstractpotion.h"

class EmptyPotion: public AbstractPotion {
	public:
	// Constructor
	EmptyPotion();

	int getAtk();
	int getDef();
	bool isPickedUp(Player *p);
	bool isPickedUp(Enemy *e);
};
#endif
