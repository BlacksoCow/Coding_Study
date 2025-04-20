main: main.o ALGraph.o SimpleLinkedList.o
	gcc main.o ALGraph.o SimpleLinkedList.o -o main
	
main.o: main.c ALGraph.h SimpleLinkedList.h Vertex.h
	gcc -c main.c
	
ALGraph.o: ALGraph.c ALGraph.h SimpleLinkedList.h Vertex.h
	gcc -c ALGraph.c
	
SimpleLinkedList.o: SimpleLinkedList.c SimpleLinkedList.h Vertex.h
	gcc -c SimpleLinkedList.c
	
clean:
	rm -f *.o main