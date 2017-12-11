#ifndef PIZZASAUCE_H
#define PIZZASAUCE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class PizzaSauce
{
    public:
        static const int MAX_STRING_LENGTH = 24;

        PizzaSauce();

        int getIdNumber() const;
        string getName() const;
        int getPriceCategory() const;
        bool getActiveState() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setPriceCategory(int newPriceCategory);
        void setActiveState(bool newState);

        friend istream& operator >> (istream& in, PizzaSauce& sauce);
        friend ostream& operator << (ostream& out, const PizzaSauce& sauce);


    private:
        int idNumber;
        char name[MAX_STRING_LENGTH];
        int priceCategory;
        bool active;

        void strToCharArr(string nameStr);
};

#endif // PIZZASAUCE_H
