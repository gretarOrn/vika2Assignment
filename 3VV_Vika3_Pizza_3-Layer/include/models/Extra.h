#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Extra
{
    public:
        Extra();

        int getIdNumber() const;
        string getName() const;
        double getPriceCategory() const;
        bool getActiveState() const;
        //int getLines() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        //void setPrice(double newPrice);
        void setPriceCategory(int newPriceCategory);
        void setActiveState(bool newState);
        void addExtra(Extra newExtra);

        //Extra* readFile();

        friend istream&  operator >> (istream& in, Extra& extra);
        friend ostream&  operator << (ostream& out, const Extra& extra);
        //friend ifstream& operator >> (ifstream& fin, Extra& extra);
        //friend ofstream& operator << (ofstream& fout, const Extra& extra);

    private:
        static const int MAX_STRING_LENGTH = 24;

        int idNumber;
        char name[MAX_STRING_LENGTH];
        int priceCategory;
        bool isActive;

        void strToCharArr(string name);

};

#endif // EXTRA_H
