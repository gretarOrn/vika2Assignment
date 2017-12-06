#include "..\..\include\services\SalaryService.h"

SalaryService::SalaryService()
{
    //ctor
}

void SalaryService::addSalary(const Salary& salary){
    if(validSalary(salary)) {
        int n = salary_repo.sizeOfList();
        string tempSSN;
        Salary* total_list = new Salary[n];
        total_list = salary_repo.salaryList();
        bool check = true;
        for(int i = 0; i < n; i++) {
            if(salary.getSSN() == total_list[i].getSSN()) {
                if(salary.getYear() == total_list[i].getYear()) {
                    if(salary.getMonth() == total_list[i].getMonth()) {
                        total_list[i] = salary;
                        salary_repo.addList(total_list, n);
                    }
                    else {
                        check = false;
                    }
                }
                else {
                    check = false;
                }
            }
            else {
                check = false;
            }
        }
        if(!check) {
            salary_repo.addSalary(salary);
        }

    }
}
bool SalaryService::validSalary(const Salary& salary){
    string name = salary.getName();
    string ssn = salary.getSSN();
    double msalary = salary.getSalary();
    int month,year;
    month = salary.getMonth();
    year = salary.getYear();

    for(unsigned int i = 0; i < name.length(); i++) {

        if(isdigit(name.at(i))) {
            throw InvalidNameException();
        }
    }
    if(ssn.length() != 10) {
        throw InvalidSSNException();
    }
    for(unsigned int i = 0; i < ssn.length(); i++) {
        if(!isdigit(ssn.at(i))) {
            throw InvalidSSNException();
        }
    }
    if(msalary < 0) {
        throw InvalidSalaryException();
    }
    if(month < 0 || month > 12) {
        throw InvalidMonthException();
    }
    if(year > 2017) {
        throw InvalidYearException();
    }
    return true;
}
Salary* SalaryService::salaryForSSN(string ssn, int& counter) {
    int n = salary_repo.sizeOfList();
    string tempSSN;
    Salary* total_list = new Salary[n];
    Salary* ssn_list = new Salary[n];
    bool check = true;
    total_list = salary_repo.salaryList();
    counter = 0;
    for(int i = 0; i < n; i++) {
        tempSSN = total_list[i].getSSN();
        for(int j = 0; (j < 10); j++) {
            if(tempSSN[j] != ssn.at(j)) {
                check = false;
            }

        }
        if(check) {
            ssn_list[counter] = total_list[i];
            counter++;
        }
        check = true;
    }
    return ssn_list;

}
double SalaryService::salaryForSSNYear(string ssn, int year) {
    int n = salary_repo.sizeOfList();
    string tempSSN;
    int tempYear;
    double totalSalary = 0;
    Salary* total_list = new Salary[n];
    total_list = salary_repo.salaryList();
    bool check = true;
    for(int i = 0; i < n; i++) {
        tempSSN = total_list[i].getSSN();
        tempYear = total_list[i].getYear();
        for(int j = 0; (j < 10); j++) {
            if(tempSSN[j] != ssn.at(j)) {
                check = false;
            }

        }

        if(check && tempYear == year) {
            totalSalary += total_list[i].getSalary();
        }
        check = true;
    }

    return totalSalary;
}
string SalaryService::highestSalaryYear(int year) {
    int n = salary_repo.sizeOfList();
    Salary* total_list = new Salary[n];
    total_list = salary_repo.salaryList();
    int sal = 0;
    int highSal = 0;
    string name;
    for (int i = 0; i < n; i++) {
        sal = 0;
        for (int j = 0; j < n; j++) {
            if (total_list[i].getSSN() == total_list[j].getSSN()) {
                sal += total_list[j].getSalary();

            }
        }
        if (sal > highSal) {
            highSal = sal;
            name = total_list[i].getName();

        }
    }
    return name;

}
