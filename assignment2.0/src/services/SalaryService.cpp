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
