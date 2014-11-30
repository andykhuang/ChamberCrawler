#ifndef ___EMPTYPOTION_H___
#define ___EMPTYPOTION_H___
#include "abstractpotion.h"

class EmptyPotion: public AbstractPotion {
	public:
	// Constructor
	EmptyPotion();

	int getAtk();
	int getDef();
	bool isUsed(Player *p);
	bool isUsed(Enemy *e);
	std::string seesPotion();
};
#endif
