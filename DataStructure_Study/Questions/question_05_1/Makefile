main: main.o CircularLinkedList.o Company.o
	gcc main.o CircularLinkedList.o Company.o -o main
	
main.o: CircularLinkedList.h Company.h main.c
	gcc -c main.c

CircularLinkedList.o: CircularLinkedList.h Company.h CircularLinkedList.c
	gcc -c CircularLinkedList.c
	
Company.o: Company.h Company.c
	gcc -c Company.c
	
clean:
	rm -f *.o main