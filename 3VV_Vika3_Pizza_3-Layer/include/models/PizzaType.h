#ifndef PIZZATYPE_H
#define PIZZATYPE_H


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class PizzaType
{
    public:
        static const int MAX_STRING_LENGTH = 24;
        PizzaType();

        int getIdNumber() const;
        string getName() const;
        double getPriceOffset() const;
        bool getActiveState() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setPriceOffset(double newPriceOffset);
        void setActiveState(bool newState);

        friend istream&  operator >> (istream& in, PizzaType& type);
        friend ostream&  operator << (ostream& out, const PizzaType& type);

    private:
        int idNumber;
        char name[MAX_STRING_LENGTH];
        double priceOffset;
        bool isActive;

        void strToCharArr(string newName);
};

#endif // PIZZATYPE_H
