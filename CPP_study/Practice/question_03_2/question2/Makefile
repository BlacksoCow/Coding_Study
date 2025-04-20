main: main.o Printer.o
	g++ main.o Printer.o -o main

main.o: Printer.h main.cpp
	g++ -c main.cpp
	
Printer.o: Printer.h Printer.cpp
	g++ -c Printer.cpp

clean:
	rm -f *.o main