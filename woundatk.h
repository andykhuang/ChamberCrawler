#ifndef ___WOUNDATK_H___
#define ___WOUNDATK_H___
#include "potion.h"

class WoundAtk:public Potion {
	public:
	WoundAtk(Potion *p);
	int getAtk();
};
#endif
