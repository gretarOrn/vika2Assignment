#include "..\..\include\UI\SalaryUI.h"

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
        cout <<"5) Exit." << endl;

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
            try {

                salary_service.addSalary(salary);
            }
            catch(InvalidNameException) {
                system("CLS");
                cout <<"Invalid name!" << endl;
            }
            catch(InvalidSSNException) {
                system("CLS");
                cout <<"Invalid SSN!" << endl;
            }
            catch(InvalidSalaryException) {
                system("CLS");
                cout <<"Invalid Salary!" << endl;
            }
            catch(InvalidMonthException) {
                system("CLS");
                cout <<"Invalid month!" << endl;
            }
            catch(InvalidYearException) {
                system("CLS");
                cout <<"Invalid Year!" << endl;
            }

        }
        else if(input == '2') {
            string ssn;
            cout <<"Enter desired SSN: ";
            cin >>ssn;

            salary_service.salaryForSSN(ssn);
            for(int i = 0; i < 10; i++) {
            }


        }
        else if(input == '3') {


        }
        else if(input == '4') {


        }
        else if(input == '5') {
            exit(0);
        }
    }
}
