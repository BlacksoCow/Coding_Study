main: main.o ALGraph.o SimpleLinkedList.o ArrayStack.o
	gcc main.o ALGraph.o SimpleLinkedList.o ArrayStack.o -o main
	
main.o: main.c ALGraph.h SimpleLinkedList.h ArrayStack.h Vertex.h
	gcc -c main.c
	
ALGraph.o: ALGraph.c ALGraph.h SimpleLinkedList.h ArrayStack.h Vertex.h
	gcc -c ALGraph.c
	
SimpleLinkedList.o: SimpleLinkedList.c SimpleLinkedList.h Vertex.h
	gcc -c SimpleLinkedList.c

ArrayStack.o: ArrayStack.c ArrayStack.h Vertex.h
	gcc -c ArrayStack.c
	
clean:
	rm -f *.o main