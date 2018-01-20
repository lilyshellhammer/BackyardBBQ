#include <iostream>
#include <cstdlib>
#include "creature.h"
#include "item.h"
#include "definitions.h"
#include "game.h"

using namespace std;

int main(){
	Game g;
	g.initCharacter();
	g.loop(); // in loop you printMenu over and over again until you quit. 
	return 0;
}