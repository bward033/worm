CFlag = -ggdb -std=c++11

worm.x: GameSquare.o worm.o spots.o freePool.o  main.o getChar.o 
	g++ $(CFlag) -o worm.x GameSquare.o main.o spots.o freePool.o worm.o getChar.o -lcurses -ltermcap
main.o: GameSquare.hpp main.cpp
	g++ $(CFlag) -c -o main.o main.cpp
GameSquare.o: GameSquare.hpp GameSquare.cpp
	g++ $(CFlag) -c -o GameSquare.o GameSquare.cpp 
freePool.o: freePool.hpp freePool.cpp 
	g++ $(CFlag) -c -o freePool.o  freePool.cpp
spots.o: spots.hpp spots.cpp
	g++ $(CFlag) -c -o spots.o spots.cpp
worm.o: worm.hpp worm.cpp
	g++ $(CFlag) -c -o worm.o worm.cpp
getChar.o: getChar.cpp
	g++ -c -ggdb -std=c++11 getChar.cpp -o getChar.o
clean: 

	rm -f *.o worm.x *~

run : worm.x
	clear
	./worm.x
