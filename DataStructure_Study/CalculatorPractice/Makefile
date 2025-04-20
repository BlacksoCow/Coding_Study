main: main.o InfixToPostfix.o ListStack.o PostCalculator.o InfixCalculator.o
	gcc main.o InfixToPostfix.o ListStack.o PostCalculator.o InfixCalculator.o -o main
	
main.o: main.c InfixToPostfix.h ListStack.h
	gcc -c main.c
	
InfixToPostfix.o: InfixToPostfix.c InfixToPostfix.h ListStack.h
	gcc -c InfixToPostfix.c
	
ListStack.o: ListStack.c ListStack.h
	gcc -c ListStack.c
	
PostCalculator.o: PostCalculator.c PostCalculator.h ListStack.h
	gcc -c PostCalculator.c
	
InfixCalculator.o: InfixCalculator.c InfixCalculator.h InfixToPostfix.h PostCalculator.h ListStack.h
	gcc -c InfixCalculator.c

clean:
	rm -f *.o main