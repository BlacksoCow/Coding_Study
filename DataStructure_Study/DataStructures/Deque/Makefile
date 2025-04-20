main: main.o Deque.o
	gcc main.o Deque.o -o main
	
main.o: main.c Deque.h
	gcc -c main.c
	
Deque.o: Deque.c Deque.h
	gcc -c Deque.c
	
clean:
	rm -f *.o main