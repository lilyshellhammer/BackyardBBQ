#include <iostream>
#include <cstdlib>
#include "definitions.h"
#include "item.h"

using namespace std;

////////////// PEACH FUNCTIONS /////////////
Peach::Peach(){
	name = "Peach";
	description = "An edible treat!";
	shape = "`@";
	numType = 1;
}
void Peach::print_shape(){
	cout << " to be created: peach" << endl;
}

int Peach::effect(Creature*c){
	if(c->hunger == 20){ //FULL_HUNGER
		return 1;
	}
	else{
		c->hunger = (c->hunger + 5)%20;//FULL_HUNGER;
		return 0;
	}
}

////////////// CHARCOAL FUNCTIONS /////////
Charcoal::Charcoal(){
	name = "Charcoal Pencil";
	description = "A way to make beautiful art";
	shape = "->";
	numType = 2;
}
void Charcoal::print_shape(){
	cout << " to be created: charcoal" << endl;
}
int Charcoal::effect(Creature *c){
	if(c->happiness == 100){//FULL_HAPPINESS){
		return 1;
	}
	else{
		c->happiness = (c->happiness +5)%100; //FULL_HAPPINESS;
		return 0;
	}
}
////////////// BEE EFFECTS /////////
Bee::Bee(){
	name = "A bee!! Ahhh";
	description = "Oh no you got a bee sting!";
	shape = "*3";
	numType = 3;
}

void Bee::print_shape(){
	cout << " to be created: bee" << endl;
}
int Bee::effect(Creature *c){
	if(c->health > 5)
		c->health -= 5;
	else
		cout << "uh oh, your health is at zero" << endl;
		c->health = 0;
	return 0; //exited normally
}
////////////// HERBS EFFECTS /////////
Herbs::Herbs(){
	name = "Medicinal Herbs";
	description = "Herbs to heal you!";
	shape = "%%";
	numType = 4;
}
void Herbs::print_shape(){
	cout << " to be created: herbs" << endl;
}
int Herbs::effect(Creature *c){
	if (c->health == 25){//FULL_HEALTH){
		cout << "Full health!" << endl;
		return 1;
	}
	else{
		c->health = (c->health +5)%25; //FULL_HEALTH;
		return 0;
	}
}