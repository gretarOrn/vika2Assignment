#ifndef SALARYUI_H
#define SALARYUI_H
#include "Employee.h"
#include "Salaryservice.h"

class SalaryUI
{
    public:
        SalaryUI();
        void mainMenu();
    private:
        Salaryservice salaryService;

};

#endif // SALARYUI_H
