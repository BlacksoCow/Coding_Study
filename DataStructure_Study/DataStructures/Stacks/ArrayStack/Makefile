main: main.o ArrayStack.o
	gcc main.o ArrayStack.o -o main
	
main.o: main.c ArrayStack.h
	gcc -c main.c
	
ArrayStack.o: ArrayStack.h ArrayStack.c
	gcc -c ArrayStack.c
	
clean:
	rm -f *.o main