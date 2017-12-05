#include "..\..\include\services\SalaryService.h"

SalaryService::SalaryService()
{
    //ctor
}

void SalaryService::addSalary(const Salary& salary){
    if(validSalary(salary)) {
        salary_repo.addSalary(salary);
    }
}
bool SalaryService::validSalary(const Salary& salary){
    string name = salary.getName();
    string ssn = salary.getSSN();
    double msalary = salary.getSalary();
    int month,year;
    month = salary.getMonth();
    year = salary.getYear();

    for(unsigned int i = 0; i < name.length(); i++) {

        if(isdigit(name.at(i))) {
            throw InvalidNameException();
        }
    }
    if(ssn.length() != 10) {
        throw InvalidSSNException();
    }
    for(unsigned int i = 0; i < ssn.length(); i++) {
        if(!isdigit(ssn.at(i))) {
            throw InvalidSSNException();
        }
    }
    if(msalary < 0) {
        throw InvalidSalaryException();
    }
    if(month < 0 || month > 12) {
        throw InvalidMonthException();
    }
    if(year > 2017) {
        throw InvalidYearException();
    }
    return true;
}
Salary* SalaryService::salaryForSSN(string ssn) {
    int size = salary_repo.sizeOfList();
    string tempSSN;
    Salary* total_list = new Salary[size];
    Salary* ssn_list = new Salary[size];
    bool check;
    int counter = 0;
    for(int i = 0; i < size; i++) {
        tempSSN = total_list[i].getSSN();
        for(int j = 0; j < 10; j++) {
            if(tempSSN[j] == ssn[j]) {
                check = true;
            }
            else {
                check = false;
            }
        }
        if(check) {
            ssn_list[counter] = total_list[i];
        }
    }
    return ssn_list;

}

