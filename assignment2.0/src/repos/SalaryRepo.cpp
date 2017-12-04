#include "..\..\include\repos\SalaryRepo.h"

SalaryRepo::SalaryRepo()
{
    //ctor
}

void SalaryRepo::addSalary(const Salary& salary) {
    ofstream fout;
    fout << salary;

}
