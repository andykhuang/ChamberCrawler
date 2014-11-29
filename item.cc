#include <string>
#include <iostream>
#include "item.h"

using namespace std;

Item::Item(){
	host = NULL;
	// TODO should we set other fields too?
}

void Item::setHost(Tile *t){
	host = t;
}

Item::~Item() {}

ostream &operator<<(ostream &out, const Item &i){
	out << i.itemSymbol;
	return out;
}
