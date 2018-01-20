#ifndef GAME_H
#define GAME_H

#include "creature.h"
#include "item.h"

using namespace std;

//Class for a single player's game. Gamestate contains as many as are made.
class Game{
public:
	Creature c;

	int itemCount;
	
	Game();
	~Game();

protected:
	//automatically filled with 50 pointers to child classes,
	//can't go over 100
	Item** items;
};


#endif