main: main.o Namespace.o
	g++ main.o Namespace.o -o main
	
main.o: Namespace.h main.cpp
	g++ -c main.cpp
	
Namespace.o: Namespace.h Namespace.cpp
	g++ -c Namespace.cpp
	
clean:
	rm -f *.o main