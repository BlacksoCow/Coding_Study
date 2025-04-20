main: main.o Friend.o
	g++ main.o Friend.o -o main

main.o: Friend.h main.cpp
	g++ -c main.cpp

Friend.o: Friend.h Friend.cpp
	g++ -c Friend.cpp

clean:
	rm -f *.o main