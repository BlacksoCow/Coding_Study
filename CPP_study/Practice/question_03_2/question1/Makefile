main: main.o Calculator.o
	g++ main.o Calculator.o -o main

main.o: Calculator.h main.cpp
	g++ -c main.cpp

Calculator.o: Calculator.h Calculator.cpp
	g++ -c Calculator.cpp
	
clean:
	rm -f *.o main