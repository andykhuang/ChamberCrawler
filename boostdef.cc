#include "potion.h"
#include "boostdef.h"

using namespace std;

int BoostDef::getDef(){
	return p->getDef() + 5;
}
