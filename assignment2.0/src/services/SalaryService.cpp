#include "SalaryService.h"

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
    /// vantar villu check hérna
    return true;
}
