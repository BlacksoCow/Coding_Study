main: main.o Rectangle.o
	g++ main.o Rectangle.o -o main
	
main.o: Rectangle.h Square.h main.cpp
	g++ -c main.cpp
	
Rectangle.o: Rectangle.h Rectangle.cpp
	g++ -c Rectangle.cpp
	
clean:
	rm -f *.o main