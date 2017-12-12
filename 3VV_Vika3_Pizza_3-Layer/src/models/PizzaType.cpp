#include "PizzaType.h"

PizzaType::PizzaType() {
    idNumber = 0;
    name[0] = '\0';
    priceOfset = 0.0;
    isActive = false;
}

///***************************************************************************************

int PizzaType::getIdNumber() const{
    return idNumber;
}

string PizzaType::getName() const{
    return name;
}

double PizzaType::getPriceOfset() const{
    return priceOfset;
}

bool PizzaType::getActiveState() const{
    return isActive;
}

///***************************************************************************************

void PizzaType::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void PizzaType::setName(string newName) {
    for(unsigned int i = 0; (i < newName.size())&&(i < MAX_STRING_LENGTH); i++) {
        name[i] = newName.at(i);
    }
    name[newName.size()] = '\0';              // Adds the esc.character after the end of the string.
    name[MAX_STRING_LENGTH - 1] = '\0';       // Adds the esc.character to the end of the charArray.
}

void PizzaType::setPriceOfset(double newPriceOfset) {
    priceOfset = newPriceOfset;
}

void PizzaType::setActiveState(bool newState) {
    isActive = newState;
}

///***************************************************************************************
/// Converts strings to a character array.
void PizzaType::strToCharArr(string nameStr) {
    for(unsigned int i = 0; (i < nameStr.size())&&(i < MAX_STRING_LENGTH); i++) {
        name[i] = nameStr.at(i);
    }
    name[nameStr.size()] = '\0';              // Adds the esc.character after the end of the string.
    name[MAX_STRING_LENGTH - 1] = '\0';       // Adds the esc.character to the end of the charArray.
}

///***************************************************************************************

istream&  operator >> (istream& in, PizzaType& type) {
    string nameStr;
    cout << "Enter type name:   ";
    in >> ws;
    getline(in, nameStr);
    type.strToCharArr(nameStr);
    cout << "Enter price category: ";
    in >> type.priceOfset;
    type.setActiveState(true);
    return in;
}

ostream& operator << (ostream& out, const PizzaType& type) {
    out << '\t' << setw(type.MAX_STRING_LENGTH) << left << type.name << " | Price category: " << type.priceOfset << endl;
    return out;
}
