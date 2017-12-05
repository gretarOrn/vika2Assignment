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
        PizzaSauce();

        int getIdNumber() const;
        string getName() const;
        int getPriceCategory() const;
        bool getActive() const;

        int getLines() const;
        PizzaSauce* readFile();
        void writeToFile() const;
        void displaySauce() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setPriceCategory(int newPriceCategory);
        void setActive(bool newState);

        friend istream& operator >> (istream& in, PizzaSauce& sauce);
        friend ostream& operator << (ostream& out, const PizzaSauce& sauce);
        friend ifstream& operator >> (ifstream& fin, PizzaSauce& sauce);
        friend ofstream& operator << (ofstream& fout, const PizzaSauce& sauce);

    private:
        static const int MAX_STRING_LENGTH = 24;

        int idNumber;
        char name[MAX_STRING_LENGTH];
        int priceCategory;
        bool active;

        void strToCharArr(string nameStr);
};

#endif // PIZZASAUCE_H
