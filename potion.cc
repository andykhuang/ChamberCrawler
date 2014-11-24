#include "abstractpotion.h"
#include "potion.h"

using namespace std;

Potion::Potion(AbstractPotion *p):p(p){}

Potion::~Potion(){
	delete p;
}
