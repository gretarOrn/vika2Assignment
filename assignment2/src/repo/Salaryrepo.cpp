#include "Salaryrepo.h"

Salaryrepo::Salaryrepo()
{
    //ctor
}

void Salaryrepo::addSalary(const Employee& employee) {
    ofstream fout;
    fout.open("Salary.txt", ios::app);
    if(fout.is_open()) {
        fout << employee;
        fout.close();
    }

}
