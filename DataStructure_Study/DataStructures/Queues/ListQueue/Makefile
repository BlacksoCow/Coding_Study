main: main.o ListQueue.o
	gcc main.o ListQueue.o -o main
	
main.o: main.c ListQueue.h
	gcc -c main.c
	
ListQueue.o: ListQueue.c ListQueue.h
	gcc -c ListQueue.c
	
clean:
	rm -f *.o main