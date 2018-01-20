#include "game.h"
#include "item.h"

using namespace std;

///////// CONSTRUCTORS AND DESTRUCTORS /////
Game::Game(){
	items = new Item*[50];
	for(int i = 0; i < 50; i++){
		items[i] = NULL;
	}
	itemCount = 0;
}

Game::~Game(){
	for(int i = 0; i < 50; i++){
		if(items[i] != NULL)
			delete items[i];
	}
	delete [] items;
	items = NULL;
}