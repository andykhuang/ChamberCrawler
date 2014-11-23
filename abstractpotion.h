#ifndef ___ABSTRACTPOTION_H___
#define ___ABSTRACTPOTION_H___
#include "item.h"

class Player;
class Enemy;

class AbstractPotion: public Item {
	public:
	virtual int getAtk() = 0;
	virtual int getDef() = 0;
	virtual bool isPickedUp(Player *p) = 0;
	virtual bool isPickedUp(Enemy *e) = 0;
	//is use
};
#endif
