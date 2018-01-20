a.out: main.cpp game.o creature.o item.o
	g++ main.cpp game.o creature.o item.o 
Item: item.cpp
	g++ -c item.cpp
Creature: creature.cpp
	g++ -c creature.cpp
Game: game.cpp
	g++ -c game.cpp


clean:
	rm -f *.o *.out