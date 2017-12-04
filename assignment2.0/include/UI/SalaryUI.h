#ifndef SALARYUI_H
#define SALARYUI_H
#include "Salary.h"
#include "SalaryService.h"

class SalaryUI
{
    public:
        SalaryUI();
        void mainMenu();
    private:
        SalaryService salary_service;
};

#endif // SALARYUI_H
