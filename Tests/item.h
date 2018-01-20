#ifndef ITEM_H
#define ITEM_H

using namespace std;
#include "creature.h"
#include <iostream>
#include <cstdlib>

class Item{
public:
	Item();
	~Item();
	int numType;
	string name;
	string description;
	string shape;
	void print_shape();
	int effect(Creature *c);
};



#endif