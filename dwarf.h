#ifndef ___DWARF_H___
#define ___DWARF_H___
#include "enemy.h"

class Dwarf: public Enemy {
	public:
	Dwarf();

	bool isAttacked(Character *c);
};
#endif
