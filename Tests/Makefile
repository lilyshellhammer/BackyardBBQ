a.out: main.cpp game.o creature.o item.o
	g++ -g main.cpp game.o creature.o item.o 
Item: item.cpp
	g++ -c -g item.cpp
Creature: creature.cpp
	g++ -c -g creature.cpp
Game: game.cpp
	g++ -c -g game.cpp

clean:
	rm -f *.o *.out