main: main.o CLStack.o CircularLinkedList.o
	gcc main.o CLStack.o CircularLinkedList.o -o main
	
main.o: main.c CLStack.h CircularLinkedList.h
	gcc -c main.c
	
CLStack.o: CLStack.c CLStack.h CircularLinkedList.h
	gcc -c CLStack.c
	
CircularLinkedList.o: CircularLinkedList.c CircularLinkedList.h
	gcc -c CircularLinkedList.c
	
clean:
	rm -f *.o main