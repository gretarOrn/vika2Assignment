#ifndef SALARYUI_H
#define SALARYUI_H
#include "..\..\include\models\Salary.h"
#include "..\..\include\services\SalaryService.h"

class SalaryUI
{
    public:
        SalaryUI();
        void mainMenu();
    private:
        SalaryService salary_service;
};

#endif // SALARYUI_H
