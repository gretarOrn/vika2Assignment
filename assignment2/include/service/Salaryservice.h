#ifndef SALARYSERVICE_H
#define SALARYSERVICE_H
#include "Salaryrepo.h"
#include "Employee.h"


class Salaryservice
{
    public:
        Salaryservice();
        void addSalary(const Employee& employee);
        bool validSalary(const Employee& employee);
    private:
        Salaryrepo salaryRepo;
};

#endif // SALARYSERVICE_H
