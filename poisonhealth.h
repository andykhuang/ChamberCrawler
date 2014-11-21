#ifndef ___POISONHEALTH_H___
#define ___POISONHEALTH_H___
#include "potion.h"

class Player;
class Enemy;

class BoostAtk:public Potion {
	public:
	bool isUsed(Player *p);
	bool isUsed(Enemy *e);
};
#endif
