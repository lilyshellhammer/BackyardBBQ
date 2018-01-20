#ifndef ITEM_H
#define ITEM_H

using namespace std;
#include "creature.h"
#include <iostream>
#include <cstdlib>

class Item{
public:
	int numType;
	string name;
	string description;
	string shape;
	virtual void print_shape() = 0;
	virtual int effect(Creature *c) = 0;
};


class Peach: public Item {
public:
	Peach();
	void print_shape();
	int effect(Creature *c);
};

class Charcoal: public Item {
public:
	Charcoal();
	void print_shape();
	int effect(Creature *c);
};

class Herbs: public Item {
public:
	Herbs();
	void print_shape();
	int effect(Creature *c);
};

class Bee: public Item {
public:
	Bee();
	void print_shape();
	int effect(Creature *c);
};

#endif
