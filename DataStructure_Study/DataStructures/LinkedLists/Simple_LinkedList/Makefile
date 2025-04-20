main: main.o SimpleLinkedList.o
	gcc main.o SimpleLinkedList.o -o main
	
main.o: main.c SimpleLinkedList.h
	gcc -c main.c
	
SimpleLinkedList.o: SimpleLinkedList.h SimpleLinkedList.c
	gcc -c SimpleLinkedList.c
	
clean:
	rm -f *.o main