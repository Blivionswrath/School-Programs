// John Goulden
// OCCC Fall 2020

// Header file for class Employee
// Similar to that used in Horstmann "Big C++" but somewhat improved

// It would be a bad thing if header files were included multiple times
// the following line of code prevents this from occurring

#pragma once

// we need a few includes

#include <string>
using namespace std;

// in a C++ class we have sections for private, public, and protected
// as usual we keep our data private and our interface public
// Note that this file is just definitions; the code will be elsewhere

class Employee
{

// our private data will just be name and salary for demo purposes

private:
	string name;
	double salary;

// the public interface will have a couple of constructors, 
// a couple of accessors ("getters") and one mutator ("setter").

public:
	Employee();
	Employee(string employee_name, double initial_salary);
	void set_salary(double new_salary);
	double get_salary() const;
	string get_name() const;

// Note the trailing semicolon! This will be explained later.

};
