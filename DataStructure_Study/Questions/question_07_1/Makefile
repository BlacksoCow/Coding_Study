main: main.o DequeQueue.o Deque.o
	gcc main.o DequeQueue.o Deque.o -o main
	
main.o: main.c DequeQueue.h Deque.h
	gcc -c main.c
	
DequeQueue.o: DequeQueue.c DequeQueue.h Deque.h
	gcc -c DequeQueue.c
	
Deque.o: Deque.c Deque.h
	gcc -c Deque.c
	
clean:
	rm -f *.o main