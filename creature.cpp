#include <iostream>
#include <cstdlib>
#include "creature.h"
//#include "definitions.h"

using namespace std;

//////// CONSTRUCTORS DESTRUCTORS //////
Creature::Creature(){
	x = 0;
	y = 0;
	//name = "unnamed";
	age = 0;

	religious = false;
	reverence = 0;

	intelligence = 0;
	health = 25;//FULL_HEALTH;
	happiness = 50;//FULL_HAPPINESS/2;
	hunger = 10;//FULL_HUNGER/2;

	design = -1;
}
 
/////// SETTERS AND GETTERS ///////

/////// FUNCTIONS //////
