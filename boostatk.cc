#include "potion.h"
#include "boostatk.h"

using namespace std;

int BoostAtk::getAtk(){
	return p->getAtk() + 5;
}
