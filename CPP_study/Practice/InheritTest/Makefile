main: main.o
	g++ main.o -o main

main.o: test.h main.cpp
	g++ -c main.cpp
	
clean:
	rm -f *.o main