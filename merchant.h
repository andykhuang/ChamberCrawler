#ifndef ___MERCHANT_H___
#define ___MERCHANT_H___
#include "enemy.h"

class Merchant: public Enemy {
	static bool isFriendly;

	public:
	// Constructor
	Merchant();

	bool isAttacked(Character *c);
};
#endif
