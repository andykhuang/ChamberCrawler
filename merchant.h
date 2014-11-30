#ifndef ___MERCHANT_H___
#define ___MERCHANT_H___
#include <string>
#include "enemy.h"

class Merchant: public Enemy {
	static bool isFriendly;
	std::string attack();

	public:
	// Constructor
	Merchant();

	std::string isAttacked(Character *c);

	// Resets how friendly Merchants are to Players
	static void resetFriendliness();
};
#endif
