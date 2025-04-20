main: main.o Account.o
	g++ main.o Account.o -o main
	
main.o: Account.h main.cpp
	g++ -c main.cpp
	
Account.o: Account.h Account.cpp
	g++ -c Account.cpp
	
clean:
	rm -f *.o main