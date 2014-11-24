#include "potion.h"
#include "boostatk.h"

using namespace std;

BoostAtk::BoostAtk(Potion *p) : Potion(p){}

int BoostAtk::getAtk(){
	return p->getAtk() + 5;
}
