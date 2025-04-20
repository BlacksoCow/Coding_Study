main: main.o Account.o AccountHandler.o
	g++ main.o Account.o AccountHandler.o -o main
	
main.o: Account.h AccountHandler.h main.cpp
	g++ -c main.cpp
	
Account.o: Account.h Account.cpp
	g++ -c Account.cpp
	
AccountHandler.o: AccountHandler.h AccountHandler.cpp
	g++ -c AccountHandler.cpp
	
clean:
	rm -f *.o main