#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee
{
    public:
        Employee(string name, string ssn, double salary, int month, int year);

    private:
        string name;
        char ssn[10];
        double salary;
        int month;
        int year;
};

#endif // EMPLOYEE_H
