#include "potion.h"
#include "boostatk.h"

using namespace std;

int Boostatk::getAtk(){
	return p->getAtk() + 5;
}
