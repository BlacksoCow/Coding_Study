main: main.o
	g++ main.o -o main
	
main.o: Book.h EBook.h main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o main