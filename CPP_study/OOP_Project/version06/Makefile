main: main.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o
	g++ main.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o -o main
	
main.o: HighCreditAccount.h AccountHandler.h main.cpp
	g++ -c main.cpp
	
Account.o: Account.h Account.cpp
	g++ -c Account.cpp
	
NormalAccount.o: NormalAccount.h NormalAccount.cpp
	g++ -c NormalAccount.cpp
	
HighCreditAccount.o: HighCreditAccount.h HighCreditAccount.cpp
	g++ -c HighCreditAccount.cpp

AccountHandler.o: AccountHandler.h AccountHandler.cpp
	g++ -c AccountHandler.cpp
	
clean:
	rm -f *.o main