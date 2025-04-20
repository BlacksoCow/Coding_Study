main: main.o BinarySearchTree.o BinaryTree.o
	gcc main.o BinarySearchTree.o BinaryTree.o -o main
	
main.o: main.c BinaryTree.h BinarySearchTree.h
	gcc -c main.c
	
BinarySearchTree.o: BinarySearchTree.c BinarySearchTree.h BinaryTree.h
	gcc -c BinarySearchTree.c

BinaryTree.o: BinaryTree.c BinaryTree.h
	gcc -c BinaryTree.c

clean:
	rm -f *.o main