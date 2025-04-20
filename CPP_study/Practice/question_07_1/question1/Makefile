main: main.o Car.o HybridCar.o HybridWaterCar.o
	g++ main.o Car.o HybridCar.o HybridWaterCar.o -o main

main.o: HybridWaterCar.h main.cpp
	g++ -c main.cpp

Car.o: Car.h Car.cpp
	g++ -c Car.cpp

HybridCar.o: HybridCar.h HybridCar.cpp
	g++ -c HybridCar.cpp

HybridWaterCar.o: HybridWaterCar.h HybridWaterCar.cpp
	g++ -c HybridWaterCar.cpp

clean:
	rm -f *.o main