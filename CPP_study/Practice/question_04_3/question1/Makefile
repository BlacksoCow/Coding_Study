main: main.o
	g++ main.o -o main

main.o: Point.h Circle.h Ring.h main.cpp
	g++ -c main.cpp
	
clean:
	rm -f *.o main