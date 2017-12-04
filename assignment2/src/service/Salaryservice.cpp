#include "Salaryservice.h"

Salaryservice::Salaryservice()
{
    //ctor
}
void Salaryservice::addSalary(const Employee& employee) {
    if(validSalary(employee)) {
        salaryRepo.addSalary(employee);
    }
    else {
        /// Error Throw
    }
}
bool Salaryservice::validSalary(const Employee& employee) {
    return true;
}
