#include "Employee.h"

Employee::Employee(string name, string ssn, double salary, int month, int year)
{
    this->name = name;
    for(unsigned int i = 0; i < ssn.size(); i++) {
        this->ssn[i] = ssn.at(i);
    }
    this->salary = salary;
    this->month = month;
    this->year = year;
}

