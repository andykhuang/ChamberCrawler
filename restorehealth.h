#ifndef ___RESTOREHEALTH_H___
#define ___RESTOREHEALTH_H___
#include "potion.h"

class Player;
class Enemy;

class RestoreHealth:public Potion {
	public:
	bool isUsed(Player *p);
	bool isUsed(Enemy *e);
};
#endif
