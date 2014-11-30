#include "floortile.h"
#include "game.h"
#include "stairs.h"
#include "item.h"

using namespace std;

Stairs::Stairs(Game *g):g(g){
	// TODO: stairs mechanics
	name = "Stairs";
	desc = "Stairs to the next Floor";
	itemSymbol = '\\';
}

bool Stairs::isPickedUp(Player *p){
	// TODO: go to the next floor
	return false;
}

bool Stairs::isPickedUp(Enemy *e){
	return false;
}

bool Stairs::canBeSteppedOn(Player *p){
	// TODO: load next floor
	g->descendFloor();
	cout << "Stairs stepped on: loading floor now" << endl;
	return true;
}

bool Stairs::canBeSteppedOn(Enemy *e){
	return false;
}
/*
bool Stairs::isSteppedOn(Player *p){
	return false;
}

bool Stairs::isOccupied(){
	return true;
}

bool Stairs::isOccupied(Player *p){
	return false;
}

bool Stairs::isOccupied(Enemy *e){
	return true;
}*/
