main: main.o BinaryTree.o AVLRebalance.o BinarySearchTree.o
	gcc main.o BinaryTree.o AVLRebalance.o BinarySearchTree.o -o main
	
main.o: main.c BinaryTree.h AVLRebalance.h BinarySearchTree.h
	gcc -c main.c
	
BinaryTree.o: BinaryTree.c BinaryTree.h
	gcc -c BinaryTree.c
	
AVLRebalance.o: AVLRebalance.c AVLRebalance.h BinaryTree.h 
	gcc -c AVLRebalance.c
	
BinarySearchTree.o: BinarySearchTree.c BinarySearchTree.h AVLRebalance.h BinaryTree.h
	gcc -c BinarySearchTree.c
	
clean:
	rm -f *.o main