#ifndef SALARYSERVICE_H
#define SALARYSERVICE_H
#include "..\..\include\models\Salary.h"
#include "..\..\include\repos\SalaryRepo.h"
#include "..\..\include\error\InvalidNameException.h"
#include "..\..\include\error\InvalidSSNException.h"
#include "..\..\include\error\InvalidSalaryException.h"
#include "..\..\include\error\InvalidMonthException.h"
#include "..\..\include\error\InvalidYearException.h"

class SalaryService
{
    public:
        SalaryService();
        void addSalary(const Salary& salary);
        Salary* salaryForSSN(string ssn, int& counter);
        double salaryForSSNYear(string ssn, int year);

    private:
        SalaryRepo salary_repo;
        bool validSalary(const Salary& salary);
};

#endif // SALARYSERVICE_H
