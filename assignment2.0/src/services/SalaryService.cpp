#include "..\..\include\services\SalaryService.h"

SalaryService::SalaryService()
{
    //ctor
}

void SalaryService::addSalary(const Salary& salary) {
    if(validSalary(salary)) {
        salary_repo.addSalary(salary);
    }
    else {
        /// Error Throw
    }
}
bool SalaryService::validSalary(const Salary& salary) {
    string name = salary.getName();
/*    string ssn = salary.getSSN();
    double msalary = salary.getSalary();
    int month,year;
    month = salary.getMonth();
    year = salary.getYear();
*/
    for(unsigned int i = 0; i < name.length(); i++) {

        if(isdigit(name[i])) {
            throw InvalidNameException();
        }
    }

    return true;
}
