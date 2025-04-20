main: main.o String.o
	g++ main.o String.o -o main
	
main.o: String.h main.cpp
	g++ -c main.cpp
	
String.o: String.h String.cpp
	g++ -c String.cpp
	
clean:
	rm -f *.o main