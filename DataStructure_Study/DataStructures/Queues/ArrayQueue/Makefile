main: main.o ArrayQueue.o
	gcc main.o ArrayQueue.o -o main
	
main.o: main.c ArrayQueue.h
	gcc -c main.c
	
ArrayQueue.o: ArrayQueue.c ArrayQueue.h
	gcc -c ArrayQueue.c
	
clean:
	rm -f *.o main