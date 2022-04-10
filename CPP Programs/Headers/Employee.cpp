// John Goulden
// OCCC Fall 2020

// Employee.cpp

// Here is the code to implement the methods in Employee.h
// So naturally we have to include that, plus a few other things we need

#include "Employee.h"
#include <string>
using namespace std;

// the double colon :: is the "scope resolution operator" and is how C++
// associates this code with the Employee class

// All of the member function names must be preceded with the class name
// note that in C++ we say "member function" and not "method"

Employee::Employee() {
	name = "John Doe";
	salary = 0.00;
}

Employee::Employee(string employee_name, double initial_salary) {
	name = employee_name;
	salary = initial_salary;
}

void Employee::set_salary(double new_salary) {
	salary = new_salary;
}

// the trailing "const" is a guarantee that these member functions do not alter state

double Employee::get_salary() const {
	return salary;
}
	
string Employee::get_name() const {
	return name;
}