#ifndef SALARYREPO_H
#define SALARYREPO_H
#include "..\..\include\models\Salary.h"
//#include <fstream>


class SalaryRepo
{
    public:
        SalaryRepo();
        void addSalary(const Salary& salary);
    private:
};

#endif // SALARYREPO_H
