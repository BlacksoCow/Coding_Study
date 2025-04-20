main: main.o BinaryTree.o BinaryTreeTraverse.o
	gcc main.o BinaryTree.o BinaryTreeTraverse.o -o main
	
main.o: main.c BinaryTree.h BinaryTreeTraverse.h
	gcc -c main.c
	
BinaryTree.o: BinaryTree.c BinaryTree.h
	gcc -c BinaryTree.c
	
BinaryTreeTraverse.o: BinaryTreeTraverse.c BinaryTreeTraverse.h BinaryTree.h
	gcc -c BinaryTreeTraverse.c

clean:
	rm -f *.o main