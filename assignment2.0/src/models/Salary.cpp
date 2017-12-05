#include "..\..\include\models\Salary.h"
Salary::Salary() {
    name = "";
    ssn = "";
    msalary = 0;
    month = 0;
    year = 0;
}
Salary::Salary(string name, string ssn, double salary, int month, int year)
{
    this->name = name;
    this->ssn = ssn;
    this->msalary = salary;
    this->month = month;
    this->year = year;
}
string Salary::getName() const{
    return this->name;
}
string Salary::getSSN() const{
    return this->ssn;
}
double Salary::getSalary() const{
    return this->msalary;
}
int Salary::getMonth() const{
    return this->month;
}
int Salary::getYear() const{
    return this->year;
}
ostream& operator <<(ostream& out, const Salary& salary) {
    out <<"Name: " << salary.name <<endl;
    out <<"SSN: "<< salary.ssn <<endl;
    out <<"Salary: " << salary.msalary << endl;
    out <<"date: " <<salary.month <<"/" << salary.year << endl;
    out <<endl;
    return out;
}
ofstream& operator <<(ofstream& fout, const Salary& salary) {
    fout.open("Salary.dat", ios::binary|ios::app);
    fout.write((char*)(&salary), sizeof(Salary));
    fout.close();

    return fout;
}
