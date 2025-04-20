main: main.o ALGraph.o SimpleLinkedList.o ArrayStack.o Heap.o
	gcc main.o ALGraph.o SimpleLinkedList.o ArrayStack.o Heap.o -o main
	
main.o: main.c ALGraph.h SimpleLinkedList.h ArrayStack.h Heap.h ALEdge.h Vertex.h
	gcc -c main.c
	
ALGraph.o: ALGraph.c ALGraph.h SimpleLinkedList.h ArrayStack.h Heap.h ALEdge.h Vertex.h
	gcc -c ALGraph.c
	
SimpleLinkedList.o: SimpleLinkedList.c SimpleLinkedList.h Vertex.h
	gcc -c SimpleLinkedList.c

ArrayStack.o: ArrayStack.c ArrayStack.h Vertex.h
	gcc -c ArrayStack.c
	
Heap.o: Heap.c Heap.h ALEdge.h Vertex.h
	gcc -c Heap.c
	
clean:
	rm -f *.o main