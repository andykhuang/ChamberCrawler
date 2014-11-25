#ifndef ___WOUNDDEF_H___
#define ___WOUNDDEF_H___
#include "potion.h"

class Player;
class Enemy;

class WoundDef:public Potion {
	static bool hasEncountered;

	public:
	// Constructor
	WoundDef(AbstractPotion *p);
	
	int getDef();

	bool isUsed(Player *p);
	bool isUsed(Enemy *e);
};
#endif
