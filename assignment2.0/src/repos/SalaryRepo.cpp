#include "..\..\include\repos\SalaryRepo.h"

SalaryRepo::SalaryRepo()
{
    //ctor
}

void SalaryRepo::addSalary(const Salary& salary) {
    ofstream fout;
    fout << salary;

}
Salary* SalaryRepo::salaryList() {
    ifstream fin;

    fin.open("Salary.dat", ios::binary);
    fin.seekg(0, fin.end);
    int recordCount = fin.tellg() / sizeof(Salary);
    fin.seekg(0, fin.beg);

    Salary* salary_list = new Salary[recordCount];
    fin.read((char*)(salary_list), recordCount * sizeof(Salary));
    fin.close();

    return salary_list;
}
int SalaryRepo::sizeOfList() {
    ifstream fin;

    fin.open("Salary.dat", ios::binary);
    fin.seekg(0, fin.end);
    int recordCount = fin.tellg() / sizeof(Salary);
    fin.close();

    return recordCount;
}
void SalaryRepo::addList(const Salary* salary, int counter) {

    ofstream fout;

    fout.open("Salary.dat", ios::binary);
    fout.clear();
    fout.write((char*)(&salary), (sizeof(Salary)*(counter)));
    fout.close();
}
