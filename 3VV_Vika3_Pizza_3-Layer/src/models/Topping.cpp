#include "Topping.h"

Topping::Topping() {
    idNumber = 0;
    name[0] = '\0';
    priceCategory = 0;
    isActive = false;
}

///***************************************************************************************

int Topping::getIdNumber() const{
    return idNumber;
}

string Topping::getName() const{
    return name;
}

int Topping::getPriceCategory() const{
    return priceCategory;
}

bool Topping::getActiveState() const{
    return isActive;
}

///***************************************************************************************

void Topping::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void Topping::setName(string newName) {
    strToCharArr(newName);
}

void Topping::setPriceCategory(int newPriceCategory) {
    priceCategory = newPriceCategory;
}

void Topping::setActiveState(bool newState) {
    isActive = newState;
}

///***************************************************************************************
/// Converts strings to a character array.
void Topping::strToCharArr(string nameStr) {
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
