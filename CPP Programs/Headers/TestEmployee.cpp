// John Goulden
// OCCC Fall 2020

// Test Employee

// Using #include with < > searches the include library
// Using #include with " " uses the file (and sometimes the path) in the quotes

#include "Employee.h"
#include<iostream>
#include <string>
using namespace std;

int main() {

	// these are all "stack" objects, instantiated at compile time
	// what familiar key word is missing here?

	// note that in the first line we don't have ()
	// but this is OK, it will invoke the default constructor

	Employee e1;
	Employee e2("Adam Smith", 12000);
	cout << "Please enter a full name: ";
	string fullName;
	getline(cin, fullName);
	cout << "Please enter a salary: ";
	double salary;
	cin >> salary;
	Employee e3(fullName, salary);
	cout << endl;
	cout << "Employee e1 is " << e1.get_name() << " with salary " << e1.get_salary() << endl;
	cout << "Employee e2 is " << e2.get_name() << " with salary " << e2.get_salary() << endl;
	cout << "Employee e3 is " << e3.get_name() << " with salary " << e3.get_salary() << endl;
	cout << endl;
	cout << "Give me a more different salary: ";
	cin >> salary;
	e3.set_salary(salary);
	cout << "Employee e3 now has salary " << e3.get_salary() << endl;

	// now let's allocate objects dynamically. 
	// it is subtly different...

	// e1, e2, and e3 are Employees
	// e4 and e5 will be pointers to Employees.

	// new always returns a pointer to an address on the heap, in every language. 

	cout << endl;

	Employee* e4 = new Employee;
	Employee* e5 = new Employee("Friedrich Hayek", 50000);
	cout << "Employee e4 is " << e4->get_name() << " with salary " << e4->get_salary() << endl;
	cout << "Employee e5 is " << e5->get_name() << " with salary " << e5->get_salary() << endl;
	cout << "Changing e4's salary to 12345.67..." << endl;
	e4->set_salary(12345.67);
	cout << "Employee e4 salary is now " << e4->get_salary() << endl;

	// C++ objects were derived from C structs.
	// In C structs the "dot" operator was used to access data elements.
	// Therefore in the first iteration of C++ classes dot is used.
	// Then came dynamic allocation of objects, and different notation was needed.
	// Therefore in C++ if you have a pointer to an object, use -> instead of .

	// In newer object-oriented languages, dynamic allocation of objects is the only game in town
	// So in Java all object names are actually pointers to objects.
	// Remember that new always returns a pointer to an address on the heap, in every language.
	// But since there's only one kind of object, the "dot" operator is used to access members

	// in other words, objects in Java (and other languages) are really pointers to objects.
	// If we were in C++ we would use -> to access the you get in Java (and others),
	// the "dot" operator is used instead of the "arrow" operator.

	return EXIT_SUCCESS;
}