#include "floortile.h"
#include "game.h"
#include "stairs.h"
#include "item.h"

using namespace std;

Stairs::Stairs(Game *g):g(g){
	name = "Stairs";
	desc = "Stairs to the next Floor";
	itemSymbol = '\\';
}

bool Stairs::isPickedUp(Player *p){
	return false;
}

bool Stairs::isPickedUp(Enemy *e){
	return false;
}

bool Stairs::canBeSteppedOn(Player *p){
	g->descendFloor();
	cout << "Stairs stepped on: descending floor" << endl;
	return true;
}

bool Stairs::canBeSteppedOn(Enemy *e){
	return false;
}
