main: main.o Bound2DArray.o BoundIntArray.o
	g++ main.o Bound2DArray.o BoundIntArray.o -o main
	
main.o: Bound2DArray.h BoundIntArray.h main.cpp
	g++ -c main.cpp
	
BoundIntArray.o: BoundIntArray.h BoundIntArray.cpp
	g++ -c BoundIntArray.cpp
	
Bound2DArray.o: BoundIntArray.h Bound2DArray.h Bound2DArray.cpp
	g++ -c Bound2DArray.cpp

clean:
	rm -f *.o main