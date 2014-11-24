#include "potion.h"
#include "wounddef.h"

using namespace std;

WoundDef::WoundDef(Potion *p):Potion(p){}

int WoundDef::getDef(){
	return p->getDef() - 5;
}
