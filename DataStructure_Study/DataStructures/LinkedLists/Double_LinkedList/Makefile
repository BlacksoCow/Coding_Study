main: main.o DoubleLinkedList.o
	gcc main.o DoubleLinkedList.o -o main
	
main.o: main.c DoubleLinkedList.h
	gcc -c main.c
	
DoubleLinkedList.o: DoubleLinkedList.h DoubleLinkedList.c
	gcc -c DoubleLinkedList.c
	
clean:
	rm -f *.o main