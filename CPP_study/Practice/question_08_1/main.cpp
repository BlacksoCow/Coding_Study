#include <iostream>
#include "TemporaryWorker.h"
#include "ForeignWorker.h"
#include "EmployeeHandler.h"
using std::cout;
using std::endl;
int main(int argc, char** argv)
{
	EmployeeHandler handler;
	
	handler.AddEmployee(new PermanentWorker("Han", 2000));
	
	SalesWorker* sw = new SalesWorker("Ryu", 3000, 0.2);
	sw->AddSalesResult(1000);
	handler.AddEmployee(sw);
	
	handler.AddEmployee(new TemporaryWorker("Kim", 5, 1500));
	
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);
	
	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);
	
	handler.ShowAllSalary();
	return 0;
}