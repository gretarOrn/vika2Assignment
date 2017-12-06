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
        PizzaType();

        int getIdNumber() const;
        string getName() const;
        int getPriceCategory() const;
        bool getActiveState() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setPriceCategory(int newPriceCategory);
        void setActiveState(bool newState);

        friend istream&  operator >> (istream& in, PizzaType& type);
        friend ostream&  operator << (ostream& out, const PizzaType& type);

    private:
        static const int MAX_STRING_LENGTH = 24;

        int idNumber;
        char name[MAX_STRING_LENGTH];
        int priceCategory;
        bool isActive;

        void strToCharArr(string newName);
};

#endif // PIZZATYPE_H
