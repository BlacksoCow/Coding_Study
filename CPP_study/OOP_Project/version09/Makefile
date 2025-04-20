main: main.o String.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o AccountArray.o
	g++ main.o String.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o  AccountArray.o -o main
	
String.o: String.h String.cpp
	g++ -c String.cpp

main.o: String.h CommonDeclare.h Account.h NormalAccount.h HighCreditAccount.h AccountHandler.h main.cpp
	g++ -c main.cpp
	
AccountArray.o: AccountArray.h AccountArray.cpp
	g++ -c AccountArray.cpp
	
Account.o: String.h CommonDeclare.h Account.h Account.cpp
	g++ -c Account.cpp
	
NormalAccount.o: String.h CommonDeclare.h Account.h NormalAccount.h NormalAccount.cpp
	g++ -c NormalAccount.cpp
	
HighCreditAccount.o: String.h CommonDeclare.h Account.h NormalAccount.h HighCreditAccount.h HighCreditAccount.cpp
	g++ -c HighCreditAccount.cpp

AccountHandler.o: AccountArray.h CommonDeclare.h Account.h NormalAccount.h HighCreditAccount.h AccountHandler.h AccountHandler.cpp
	g++ -c AccountHandler.cpp
	
clean:
	rm -f *.o main