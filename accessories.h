#ifndef ACCESSORIES_H
#define CACCESSORIES_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Accessory {
public:
	string name;
	virtual void print() = 0;
};

class Pearls: public Accessory{
public:
	void print();
};


#endif