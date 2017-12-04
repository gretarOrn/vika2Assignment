#ifndef SALARY_H
#define SALARY_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Salary
{
    public:
        Salary(string name, string ssn, double salary, int month, int year);
        string getName();
        char* getSSN();
        double getSalary();
        int getMonth();
        int getYear();

        friend ostream& operator <<(ostream& out, const Salary& salary);
        friend ofstream& operator <<(ofstream& fout, const Salary& salary);
    private:
        string name;
        char ssn[10];
        double msalary;
        int month;
        int year;
};

#endif // SALARY_H
