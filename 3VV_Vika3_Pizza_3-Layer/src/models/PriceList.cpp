#include "PriceList.h"

PriceList::PriceList()
{
    idNumber = 0;
    name[0] = '\0';
    price = 0.0;
    isActive = false;
}

///***************************************************************************************

int PriceList::getIdNumber() const {
    return idNumber;
}
string PriceList::getName() const {
    return name;
}
double PriceList::getPrice() const {
    return price;
}
bool PriceList::getActiveState() const {
    return isActive;
}

///***************************************************************************************

void PriceList::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}
void PriceList::setName(string newName) {
    strToCharArr(newName);
}
void PriceList::setPrice(double newPrice) {
    price = newPrice;
}
void PriceList::setActiveState(bool newState) {
    isActive = newState;
}

///***************************************************************************************
/// Converts strings to a character array.
void PriceList::strToCharArr(string nameStr) {
    for(unsigned int i = 0; i < nameStr.size(); i++) {
        if(i == MAX_STRING_LENGTH -1) {
            break;
        }
        name[i] = nameStr.at(i);
    }
    name[nameStr.size()] = '\0';                // Adds the esc.character after the end of the string.
    name[MAX_STRING_LENGTH - 1] = '\0';         // Adds the esc.character to the end of the charArray.
}

///***************************************************************************************

istream& operator >> (istream& in, PriceList& price) {
    return in;
}

ostream& operator << (ostream& out, const PriceList& price) {
    return out;
}
