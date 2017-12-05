#include "PizzaSize.h"

PizzaSize::PizzaSize() {
    idNumber = 0;
    name[0] = '\0';
    priceCategory = 0;
    isActive = false;
}

///***************************************************************************************

int PizzaSize::getIdNumber() const{
    return idNumber;
}

string PizzaSize::getName() const{
    return name;
}

int PizzaSize::getPriceCategory() const{
    return priceCategory;
}

bool PizzaSize::getActiveState() const{
    return isActive;
}

///***************************************************************************************

void PizzaSize::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void PizzaSize::setName(string newName) {
    strToCharArr(newName);
}

void PizzaSize::setPriceCategory(int newPriceCategory) {
    priceCategory = newPriceCategory;
}

void PizzaSize::setActiveState(bool newState) {
    isActive = newState;
}

///***************************************************************************************
/// Converts strings to a character array.
void PizzaSize::strToCharArr(string nameStr) {
    for(unsigned int i = 0; i < nameStr.size(); i++) {
        if(i == MAX_STRING_LENGTH -1) {
            break;
        }
        this->name[i] = nameStr.at(i);
    }
    this->name[nameStr.size()] = '\0';              // Adds the esc.character after the end of the string.
    this->name[MAX_STRING_LENGTH - 1] = '\0';       // Adds the esc.character to the end of the charArray.
}

///***************************************************************************************

istream&  operator >> (istream& in, PizzaSize& size) {
    string nameStr;
    cout << "Enter size name:   ";
    in >> ws;
    getline(in, nameStr);
    size.strToCharArr(nameStr);
    cout << "Enter price category: ";
    in >> size.priceCategory;
    size.setActiveState(true);
    return in;
}

ostream& operator << (ostream& out, const PizzaSize& size) {
    out << size.idNumber << ")\t" << setw(size.MAX_STRING_LENGTH) << left << size.name << " | Price category: " << size.priceCategory << endl;
    return out;
}
