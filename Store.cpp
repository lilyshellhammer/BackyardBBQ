#include "game.h"
#include "item.h"
#include "string.h"
#include "stdlib.h"

using namespace std;

//CONSTR DESTR

Store::Store(){
	numPeaches = 0;
	numCharcoals = 0;
	numHerbs = 0;

	numItems = 10;
	items = new Item*[numItems];

	for(int i = 0; i < numItems; i++){
		if(i%3 == 0){
			items[i] = new Peach;
			numPeaches++;
		}
		else if(i%3 == 1){
			items[i] = new Charcoal;
			numCharcoals++;
		}
		else{
			items[i] = new Herbs;
			numHerbs++;
		}
	}
}

Store::~Store(){
	for(int i = 0; i < numItems; i++){
		delete items[i];
	}
	delete [] items;
}

//Getters and setters

void Store::restock(){

}

int Store::buy(int i){

}
