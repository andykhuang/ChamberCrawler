#ifndef ___ABSTRACTPOTION_H___
#define ___ABSTRACTPOTION_H___
#include "item.h"

class Player;
class Enemy;

class AbstractPotion: public Item {
	public:
	virtual int getAtk() = 0;
	virtual int getDef() = 0;
	virtual bool isUsed(Player *p);
	virtual bool isUsed(Enemy *e);
}
#endif
