#ifndef PRICELIST_H
#define PRICELIST_H

#include <string>
using namespace std;

class PriceList
{
    public:
        static const int MAX_STRING_LENGTH = 24;
        PriceList();

        int getIdNumber() const;
        string getName() const;
        double getPrice() const;
        bool getActiveState() const;

        void setIdNumber(int newIdNumber);
        void setName(string newName);
        void setPrice(double newPrice);
        void setActiveState(bool newState);
        //PriceList* readFile();

        friend istream& operator >> (istream& in, PriceList& price);
        friend ostream& operator << (ostream& out, const PriceList& price);
        //friend ifstream& operator >> (ifstream& fin, PriceList& price);
        //friend ofstream& operator << (ofstream& fout, const PriceList& price);

    private:
        int idNumber;
        char name[MAX_STRING_LENGTH];
        double price;
        bool isActive;

        void strToCharArr(string nameStr);
};

#endif // PRICELIST_H
