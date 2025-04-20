main: main.o FruitSeller.o FruitBuyer.o
	g++ main.o FruitSeller.o FruitBuyer.o -o main
	
main.o: FruitSeller.h FruitBuyer.h main.cpp
	g++ -c main.cpp
	
FruitSeller.o: FruitSeller.h FruitSeller.cpp
	g++ -c FruitSeller.cpp

FruitBuyer.o: FruitBuyer.h FruitBuyer.cpp
	g++ -c FruitBuyer.cpp
	
clean:
	rm -f *.o main