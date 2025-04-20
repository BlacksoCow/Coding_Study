main: main.o Point.o Rectangle.o
	g++ main.o Point.o Rectangle.o -o main
	
Point.o: Point.h Point.cpp
	g++ -c Point.cpp
	
Rectangle.o: Rectangle.h Rectangle.cpp
	g++ -c Rectangle.cpp
	
clean:
	rm -f *.o main