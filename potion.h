#ifndef ___POTION_H___
#define ___POTION_H___
#include "abstractpotion.h"

class Player;

class Potion: public AbstractPotion {
	protected:
	AbstractPotion *p;
	virtual bool isConsumed(Player *p);

	public:
	// Constructor
	Potion(AbstractPotion *p);

	// Default implementation for getAtk() and getDef()
	// Required since each potion only overrides one or the other
	int getAtk();
	int getDef();

	// Destructor
	~Potion();
};
#endif
