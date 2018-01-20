#ifndef GAME_H
#define GAME_H

#include "creature.h"
#include "item.h"
#include "definitions.h"
#include "store.h"
#include "string.h"
using namespace std;

//Class for a single player's game. Gamestate contains as many as are made.
class Game{
public:
	char** Board;
	Creature c;
	Store s;
	bool firstTime;
	int money;
	int level;

	int day;

	int itemCount;

	Game();
	~Game();

	void loop();

	void printBoard();
	void initBoard();
	void gamePlay();
	void printHeader();
	void initCharacter();
	void printMenu();
	void printDesigns();
	void  initItems();
	//Within print menu
	void walkAround();
	void useItem();
	void buyStore();

	void showItemsFunc();

	void addItems(int numType);
	int useItem(int n);

	int checkItemInt(string answer, int top);
	void printItems();
	void displayIndividualItem(int position);

	void bees(Creature *c);
	void peach();
	void mythicalLlama();

	void deleteItemChoice();
	void deleteItem(int n);

protected:
	//automatically filled with 50 pointers to child classes,
	//can't go over 100
	Item** items;
};


#endif