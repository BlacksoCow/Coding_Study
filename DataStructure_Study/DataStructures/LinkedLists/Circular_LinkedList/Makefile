main: main.o CircularLinkedList.o
	gcc main.o CircularLinkedList.o -o main
	
main.o: main.c CircularLinkedList.h
	gcc -c main.c
	
CircularLinkedList.o: CircularLinkedList.h CircularLinkedList.c
	gcc -c CircularLinkedList.c
	
clean:
	rm -f *.o main