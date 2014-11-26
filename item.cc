#include <string>
#include <iostream>
#include "item.h"

using namespace std;

Item::Item(){
	host = NULL;
}

void Item::setHost(Tile *t){
	host = t;
}

Item::~Item() {}

ostream &operator<<(ostream &out, const Item &i){
	out << i.itemSymbol;
	return out;
}
