#ifndef ___ABSTRACTPOTION_H___
#define ___ABSTRACTPOTION_H___
#include "item.h"

class Player;
class Enemy;

class AbstractPotion: public Item {
	public:
	// Constructor
	AbstractPotion();	

	virtual bool isUsed(Player *p) = 0;
	virtual bool isUsed(Enemy *e) = 0;
	virtual int getAtk() = 0;
	virtual int getDef() = 0;

	// Destructor
	virtual ~AbstractPotion();
};
#endif
