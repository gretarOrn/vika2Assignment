#ifndef PRICELIST_H
#define PRICELIST_H

#include <iostream>
#include <fstream>
using namespace std;

class PriceList
{
    public:
        PriceList();

        PriceList* readFile();
        void strToCharArr(string nameStr);

        friend istream& operator >> (istream& in, PriceList& price);
        friend ostream& operator << (ostream& out, const PriceList& price);
        friend ifstream& operator >> (ifstream& fin, PriceList& price);
        friend ofstream& operator << (ofstream& fout, const PriceList& price);

    private:
        static const int MAX_STRING_LENGTH = 24;

        char name[MAX_STRING_LENGTH];
        double price;
};

#endif // PRICELIST_H
