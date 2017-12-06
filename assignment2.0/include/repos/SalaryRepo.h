#ifndef SALARYREPO_H
#define SALARYREPO_H
#include "..\..\include\models\Salary.h"
#include <vector>



class SalaryRepo
{
    public:
        SalaryRepo();
        void addSalary(const Salary& salary);
        void addList(const Salary* salary, int counter);
        Salary* salaryList();
        int sizeOfList();

    private:
};

#endif // SALARYREPO_H
