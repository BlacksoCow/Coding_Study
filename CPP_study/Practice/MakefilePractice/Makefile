main: main.o
	g++ main.o -o main
	
main.o: headerone.h headertwo.h headerthree.h main.cpp
	g++ -c main.cpp
	
clean:
	rm -f *.o main