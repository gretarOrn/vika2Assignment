#ifndef SALARYSERVICE_H
#define SALARYSERVICE_H
#include "Salary.h"
#include "..\repos\SalaryRepo.h"

class SalaryService
{
    public:
        SalaryService();
        void addSalary(const Salary& salary);
        bool validSalary(const Salary& salary);
    private:
        SalaryRepo salary_repo;
};

#endif // SALARYSERVICE_H
