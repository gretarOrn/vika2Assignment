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

        string getName() const;
        double getPrice() const;
        int getLines() const;

        void setName(string newName);
        void setPrice(double newPrice);
        void setPriceingCategory(int newPriceCategory);

        Extra* readFile();

        friend istream&  operator >> (istream& in, Extra& extra);
        friend ostream&  operator << (ostream& out, const Extra& extra);
        friend ifstream& operator >> (ifstream& fin, Extra& extra);
        friend ofstream& operator << (ofstream& fout, const Extra& extra);

    private:
        static const int MAX_STRING_LENGTH = 24;

        char name[MAX_STRING_LENGTH];
        int priceCategory;

        void strToCharArr(string name);

};

#endif // EXTRA_H
