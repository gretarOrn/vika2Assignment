#include "SalaryRepo.h"

SalaryRepo::SalaryRepo()
{
    //ctor
}

void addSalary(Salary salary) {
    ofstream fout;
    fout.open("Salary.txt", ios::app);
    if(fout.is_open()) {
        fout << salary;
        fout.close();
    }
}
