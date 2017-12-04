#include "Salary.h"

Salary::Salary(string name, string ssn, double salary, int month, int year)
{
    this->name = name;
    for(unsigned int i = 0; i < ssn.size(); i++) {
        this->ssn[i] = ssn.at(i);
    }
    this->msalary = salary;
    this->month = month;
    this->year = year;
}
string Salary::getName(){
    return name;
}
char* Salary::getSSN() {
    return ssn;
}
double Salary::getSalary() {
    return msalary;
}
int Salary::getMonth() {
    return month;
}
int Salary::getYear() {
    return year;
}
ostream& operator <<(ostream& out, const Salary& salary) {
    out <<"Name: " << salary.name <<endl;
    out <<"SSN: "<< salary.ssn <<endl;
    out <<"Salary: " << salary.msalary << endl;
    out <<"date: " <<salary.month <<"/" << salary.year << endl;
    return out;
}

