main: main.o Account.o AccountFunc.o
	g++ main.o Account.o AccountFunc.o -o main
	
main.o: Account.h AccountFunc.h main.cpp
	g++ -c main.cpp
	
Account.o: Account.h Account.cpp
	g++ -c Account.cpp
	
AccountFunc.o: AccountFunc.h AccountFunc.cpp
	g++ -c AccountFunc.cpp

clean:
	rm -f *.o main