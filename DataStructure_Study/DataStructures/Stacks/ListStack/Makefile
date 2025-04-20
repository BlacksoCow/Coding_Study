main: main.o ListStack.o
	gcc main.o ListStack.o -o main
	
main.o: main.c ListStack.h
	gcc -c main.c
	
ListStack.o: ListStack.h ListStack.c
	gcc -c ListStack.c
	
clean:
	rm -f *.o main