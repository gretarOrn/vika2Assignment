#ifndef SALARYREPO_H
#define SALARYREPO_H
#include <fstream>
#include "Employee.h"


class Salaryrepo
{
    public:
        Salaryrepo();
        void addSalary(const Employee& employee);
    private:
};

#endif // SALARYREPO_H
