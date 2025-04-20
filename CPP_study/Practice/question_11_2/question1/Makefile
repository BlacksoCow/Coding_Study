main: main.o BoundIntArray.o BoundPointArray.o
	g++ main.o BoundIntArray.o BoundPointArray.o -o main
	
main.o: BoundIntArray.h Point.h BoundPointArray.h main.cpp
	g++ -c main.cpp
	
BoundIntArray.o: BoundIntArray.h BoundIntArray.cpp
	g++ -c BoundIntArray.cpp
	
BoundPointArray.o: Point.h BoundIntArray.h BoundPointArray.cpp
	g++ -c BoundPointArray.cpp

clean:
	rm -f *.o main