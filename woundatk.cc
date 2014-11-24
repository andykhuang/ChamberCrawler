#include "potion.h"
#include "woundatk.h"

using namespace std;

WoundAtk::WoundAtk(Potion *p) : Potion(p){}

int WoundAtk::getAtk(){
	return p->getAtk() - 5;
}
