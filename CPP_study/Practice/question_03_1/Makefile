main: main.o Point.o
	g++ main.o Point.o -o main

main.o: Point.h main.cpp
	g++ -c main.cpp
	
Point.o: Point.h Point.cpp
	g++ -c Point.cpp

clean:
	rm -f *.o main