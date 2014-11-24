#ifndef ___WOUNDDEF_H___
#define ___WOUNDDEF_H___
#include "potion.h"

class WoundDef:public Potion {
	public:
	WoundDef(Potion *p);
	int getDef();
};
#endif
