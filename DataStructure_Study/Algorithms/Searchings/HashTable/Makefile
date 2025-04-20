main: main.o Person.o SimpleLinkedList.o Table.o
	gcc main.o Person.o SimpleLinkedList.o Table.o -o main
	
main.o: main.c Person.h SimpleLinkedList.h Slot.h Table.h
	gcc -c main.c
	
Person.o: Person.c Person.h
	gcc -c Person.c
	
SimpleLinkedList.o: SimpleLinkedList.c SimpleLinkedList.h Slot.h
	gcc -c SimpleLinkedList.c
	
Table.o: Table.c Table.h Slot.h SimpleLinkedList.h
	gcc -c Table.c
	
clean:
	rm -f *.o main