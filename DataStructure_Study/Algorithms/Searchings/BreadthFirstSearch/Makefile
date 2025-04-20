main: main.o ALGraph.o SimpleLinkedList.o ArrayQueue.o
	gcc main.o ALGraph.o SimpleLinkedList.o ArrayQueue.o -o main
	
main.o: main.c ALGraph.h SimpleLinkedList.h ArrayQueue.h Vertex.h
	gcc -c main.c
	
ALGraph.o: ALGraph.c ALGraph.h SimpleLinkedList.h ArrayQueue.h Vertex.h
	gcc -c ALGraph.c
	
SimpleLinkedList.o: SimpleLinkedList.c SimpleLinkedList.h Vertex.h
	gcc -c SimpleLinkedList.c

ArrayQueue.o: ArrayQueue.c ArrayQueue.h Vertex.h
	gcc -c ArrayQueue.c
	
clean:
	rm -f *.o main