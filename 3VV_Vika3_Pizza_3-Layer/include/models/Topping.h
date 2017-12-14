#ifndef TOPPING_H
#define TOPPING_H


#include <string>
using namespace std;


class Topping
{
    public:
        static const int MAX_STRING_LENGTH = 24;
        Topping();

        int getIdNumber() const;
        string getName() const;
        int getPriceCategory() const;
        bool getActiveState() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setPriceCategory(int newPriceCategory);
        void setActiveState(bool newState);

        friend istream&  operator >> (istream& in, Topping& topping);
        friend ostream&  operator << (ostream& out, const Topping& topping);

    private:
        int idNumber;
        char name[MAX_STRING_LENGTH];
        int priceCategory;
        bool isActive;

        void strToCharArr(string name);
/*
    public:
        Topping();

        string getName() const;
        int getPriceingCategory() const;
        int getLines() const;

        void setName(string newName);
        void setPriceingCategory(int newPriceCategory);

        Topping* readFile();

        friend istream&  operator >> (istream& in, Topping& topping);
        friend ostream&  operator << (ostream& out, const Topping& topping);
        friend ifstream& operator >> (ifstream& fin, Topping& topping);
        friend ofstream& operator << (ofstream& fout, const Topping& topping);

    private:
        static const int MAX_STRING_LENGTH = 24;

        char name[MAX_STRING_LENGTH];
        int pricingCategory;

        void strToCharArr(string name);
*/
};

#endif // TOPPING_H
