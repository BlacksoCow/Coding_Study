main: main.o EmployeeHandler.o
	g++ main.o EmployeeHandler.o -o main
	
main.o: TemporaryWorker.h ForeignWorker.h EmployeeHandler.h main.cpp
	g++ -c main.cpp
	
EmployeeHandler.o: EmployeeHandler.h EmployeeHandler.cpp
	g++ -c EmployeeHandler.cpp
	
clean:
	rm -f *.o main