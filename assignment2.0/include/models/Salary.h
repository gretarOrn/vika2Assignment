#ifndef SALARY_H
#define SALARY_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
static const int MAX_SIZE = 11;


class Salary
{
    public:
        Salary();
        Salary(string name, string ssn, double salary, int month, int year);
        string getName() const;
        string getSSN() const;
        double getSalary() const;
        int getMonth() const;
        int getYear() const;

        friend ostream& operator <<(ostream& out, const Salary& salary);
        friend ofstream& operator <<(ofstream& fout, const Salary& salary);
    private:
        char name[MAX_SIZE];
        char ssn[MAX_SIZE];
        double msalary;
        int month;
        int year;
        void strToCharArrayName(string str);
        void strToCharArraySSN(string str);
};

#endif // SALARY_H
