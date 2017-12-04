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
string Employee::getName(){
    return name;
}
char* Employee::getSSN() {
    return ssn;
}
double Employee::getSalary() {
    return salary;
}
int Employee::getMonth() {
    return month;
}
int Employee::getYear() {
    return year;
}
