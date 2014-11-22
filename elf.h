#ifndef ___ELF_H___
#define ___ELF_H___
#include <string>
#include "enemy.h"

class Elf: public Enemy {
	public:
	// Constructor
	Elf();

	bool attack(std::string dir);
};
#endif
