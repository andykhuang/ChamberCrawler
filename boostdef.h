#ifndef ___BOOSTDEF_H___
#define ___BOOSTDEF_H___
#include "potion.h"

class BoostDef:public Potion {
	public:
	BoostDef(Potion *p);
	int getDef();
};
#endif
