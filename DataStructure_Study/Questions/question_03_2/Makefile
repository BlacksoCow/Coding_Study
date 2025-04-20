main: main.o ArrayList.o NameCard.o
	gcc main.o ArrayList.o NameCard.o -o main

main.o: NameCard.h ArrayList.h main.c
	gcc -c main.c
	
ArrayList.o: ArrayList.h NameCard.h ArrayList.c
	gcc -c ArrayList.c
	
NameCard.o: NameCard.h NameCard.c
	gcc -c NameCard.c
	
clean:
	rm -f *.o main