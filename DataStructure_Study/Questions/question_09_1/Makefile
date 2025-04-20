main: main.o Heap.o
	gcc main.o Heap.o -o main
	
main.o: main.c Heap.h
	gcc -c main.c
	
Heap.o: Heap.c Heap.h
	gcc -c Heap.c
	
clean:
	rm -f *.o main