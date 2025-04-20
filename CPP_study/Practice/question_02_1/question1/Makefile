main: main.o Function.o
	g++ main.o Function.o -o main

main.o: Function.h main.cpp
	g++ -c main.cpp

Function.o: Function.h Function.cpp
	g++ -c Function.cpp
	
clean:
	rm -f *.o main