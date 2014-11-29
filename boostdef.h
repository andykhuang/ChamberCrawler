#ifndef ___BOOSTDEF_H___
#define ___BOOSTDEF_H___
#include "potion.h"

class BoostDef:public Potion {
	static bool hasEncountered;

	public:
	// Constructor
	BoostDef(AbstractPotion *p);

	int getDef();

	bool isUsed(Player *p);
	bool isUsed(Enemy *e);};
#endif
