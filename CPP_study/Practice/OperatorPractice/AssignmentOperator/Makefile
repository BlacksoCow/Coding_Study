main: main.o Point.o
	g++ main.o Point.o -o main
	
main.o: IOS.h Point.h main.cpp
	g++ -c main.cpp
	
Point.o: IOS.h Point.h Point.cpp
	g++ -c Point.cpp
	
clean:
	rm -f *.o main