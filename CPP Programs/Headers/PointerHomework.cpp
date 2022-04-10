

using namespace std;
#include <iostream>
#include "Employee.h"
int main()
{
	Employee harry = Employee("Hacker, Harry", 35000);
	Employee boss = harry;
	Employee* pharry = new Employee("Hacker, Harry", 35000);
	Employee* pboss = pharry;
	boss.set_salary(45000);
	(*pboss).set_salary(45000);
	cout << harry.get_salary() << endl;
	cout << boss.get_salary() << endl;
	cout << pharry->get_salary() << endl;
	cout << pboss->get_salary() << endl;

}

