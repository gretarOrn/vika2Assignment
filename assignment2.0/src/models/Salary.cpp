#include "..\..\include\models\Salary.h"
Salary::Salary() {
    name[0] = '\0';
    ssn[0] = '\0';
    msalary = 0;
    month = 0;
    year = 0;
}
Salary::Salary(string name, string ssn, double salary, int month, int year)
{
    strToCharArrayName(name);
    strToCharArraySSN(ssn);
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
void Salary::strToCharArrayName(string str) {
    int n = str.size();
    for ( int i = 0; i < n; i++) {
        this->name[i] = str[i];
    }
    this->name[n] = '\0';
    this->name[MAX_SIZE] = '\0';

}
void Salary::strToCharArraySSN(string str) {
    int n = str.size();
    for ( int i = 0; i < n; i++) {
        this->ssn[i] = str[i];
    }
    this->ssn[n] = '\0';
    this->ssn[MAX_SIZE] = '\0';

}

