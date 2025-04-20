main: main.o SimpleLinkedList.o Point.o
	gcc main.o SimpleLinkedList.o Point.o -o main
	
main.o: main.c SimpleLinkedList.h Point.h
	gcc -c main.c
	
SimpleLinkedList.o: SimpleLinkedList.h SimpleLinkedList.c
	gcc -c SimpleLinkedList.c
	
Point.o: Point.h Point.c
	gcc -c Point.c
	
clean:
	rm -f *.o main