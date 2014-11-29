#ifndef ___DWARF_H___
#define ___DWARF_H___
#include <string>
#include "enemy.h"

class Dwarf: public Enemy {
	public:
	Dwarf();

	std::string isAttacked(Character *c);
};
#endif
