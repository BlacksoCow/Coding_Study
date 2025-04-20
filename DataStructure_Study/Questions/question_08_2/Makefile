main: main.o ExpressionTree.o BinaryTree.o BinaryTreeTraverse.o ListStack.o
	gcc main.o ExpressionTree.o BinaryTree.o BinaryTreeTraverse.o ListStack.o -o main

main.o: main.c BinaryTree.h BinaryTreeTraverse.h
	gcc -c main.c
	
ExpressionTree.o: ExpressionTree.c ExpressionTree.h BinaryTree.h BinaryTreeTraverse.h ListStack.h
	gcc -c ExpressionTree.c	
	
BinaryTree.o: BinaryTree.c BinaryTree.h
	gcc -c BinaryTree.c
	
BinaryTreeTraverse.o: BinaryTreeTraverse.c BinaryTreeTraverse.h BinaryTree.h
	gcc -c BinaryTreeTraverse.c

ListStack.o: ListStack.c ListStack.h
	gcc -c ListStack.c

clean:
	rm -f *.o main