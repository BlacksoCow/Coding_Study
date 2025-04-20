main: main.o ArrayList.o
	gcc main.o ArrayList.o -o main
	
main.o: ArrayList.h main.c
	gcc -c main.c
	
ArrayList.o: ArrayList.h ArrayList.c
	gcc -c ArrayList.c
	
clean:
	rm -f *.o main