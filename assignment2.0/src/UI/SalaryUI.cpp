#include "SalaryUI.h"

SalaryUI::SalaryUI()
{
    //ctor
}
void SalaryUI::mainMenu() {
    char input;
    cout <<"Salary menu" << endl;

    while(true) {
        cout <<"choose an action:" <<endl;
        cout <<"1) add a salary to the records." << endl;
        cout <<"2) get all salary records for a given SSN." << endl;
        cout <<"3) get total salary for a given year and a given SSN." << endl;
        cout <<"4) get the name of employee with the highest total salary for a given year." << endl;

        cin >>input;
        if(input == '1') {
            string name,SSN;
            double msalary;
            int month,year;
            cout <<"Name: ";
            cin >>name;
            cout <<"SSN: ";
            cin >>SSN;
            cout <<"Salary: ";
            cin >>msalary;
            cout <<"Month: ";
            cin >>month;
            cout <<"Year: ";
            cin >>year;
            Salary salary(name,SSN,msalary,month,year);
            salary_service.addSalary(salary);

        }
        else if(input == '2') {


        }
        else if(input == '2') {


        }
        else if(input == '2') {


        }
        else {
            cout <<"\nWrong input." << endl;
        }

    }
}
