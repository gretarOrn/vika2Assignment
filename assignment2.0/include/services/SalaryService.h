#ifndef SALARYSERVICE_H
#define SALARYSERVICE_H
#include "..\..\include\models\Salary.h"
#include "..\..\include\repos\SalaryRepo.h"
#include "InvalidNameException.h"

class SalaryService
{
    public:
        SalaryService();
        void addSalary(const Salary& salary);

    private:
        SalaryRepo salary_repo;
        bool validSalary(const Salary& salary);
};

#endif // SALARYSERVICE_H
