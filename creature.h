#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Creature {
public:
	int x; //x position on board
	int y; //y positin on board

	string name; //character name
	int age;	//character age

	int health;
	int hunger;
	int happiness;
	int intelligence;
	//option for religion
	bool religious;
	int reverence;
	//what character looks like
	int design;

	Creature();
};

#endif