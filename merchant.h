#ifndef ___MERCHANT_H___
#define ___MERCHANT_H___
#include <string>
#include "enemy.h"

class Merchant: public Enemy {
	static bool isFriendly;

	public:
	// Constructor
	Merchant();

	std::string isAttacked(Character *c);
};
#endif
