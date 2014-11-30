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

bool Item::isUsed(Player *p) {
	return false;
}

bool Item::isUsed(Enemy *e) {
	return false;
}

string Item::getName() {
	return name;
}

string Item::seesPotion(){
	return "";
}

Item::~Item() {}

ostream &operator<<(ostream &out, const Item &i){
	out << i.itemSymbol;
	return out;
}
