#include <string>
#include "enemy.h"
#include "dragon.h"

using namespace std;

Dragon::Dragon(){
	characterSymbol = 'D';
}

bool Dragon::attack(string dir){
	return false;
}
