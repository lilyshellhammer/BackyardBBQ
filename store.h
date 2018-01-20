#ifndef STORE_H
#define STORE_H

using namespace std;
#include "creature.h"
#include <iostream>
#include <cstdlib>


class Store{
public:
	Store();
	~Store();

	int buy(int i);
	void restock();
	int prices[3];
	int numItems;
	int numPeaches;
	int numCharcoals;
	int numHerbs;

private:
	Item** items;
};

#endif