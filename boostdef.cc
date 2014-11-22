#include "potion.h"
#include "boostdef.h"

using namespace std;

BoostDef::BoostDef(Potion *p):Potion(p){}

int BoostDef::getDef(){
	return p->getDef() + 5;
}
