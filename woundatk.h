#ifndef ___WOUNDATK_H___
#define ___WOUNDATK_H___
#include "potion.h"

class WoundAtk:public Potion {
	static bool hasEncountered;

	public:
	// Constructor
	WoundAtk(AbstractPotion *p);

	int getAtk();

	bool isUsed(Player *p);
	bool isUsed(Enemy *e);};
#endif
