#include "floortile.h"
#include "game.h"
#include "stairs.h"

using namespace std;

Stairs::Stairs(Game *g):g(g){
	// TODO: stairs mechanics
}

bool Stairs::isSteppedOn(Player *p){
	return false;
}

bool Stairs::isOccupied(Player *p){
	return false;
}

bool Stairs::isOccupied(Enemy *e){
	return true;
}
