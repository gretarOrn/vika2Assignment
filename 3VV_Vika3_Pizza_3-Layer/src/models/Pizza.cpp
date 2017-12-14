#include "Pizza.h"

Pizza::Pizza() {
    idNumber = 0;
    name[0] = '\0';
    totalPrice = 0.0;
    isActive = false;
}

///***************************************************************************************

int Pizza::getIdNumber() const {
    return idNumber;
}

string Pizza::getName() const {
    return name;
}

PizzaSize Pizza::getSize() const {
    return size;
}

PizzaType Pizza::getType() const {
    return type;
}

PizzaSauce Pizza::getSauce() const {
    return sauce;
}

Topping* Pizza::getToppings() {
    return toppings;
}

double Pizza::getTotalPrice() const {
    return totalPrice;
}

bool Pizza::getActiveState() const {
    return isActive;
}

///***************************************************************************************

void Pizza::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void Pizza::setName(string newName) {
    strToCharArr(newName);
}

void Pizza::setSize(const PizzaSize& newSize) {  /// takes in reference of size and puts it into the pizza
    size.setIdNumber(newSize.getIdNumber());
    size.setName(newSize.getName());
    size.setPriceCategory(newSize.getPriceCategory());
    size.setToppingMult(newSize.getToppingMult());
    size.setToppingOffset(newSize.getToppingMult());
    size.setActiveState(newSize.getActiveState());
}

void Pizza::setType(const PizzaType& newType) {  /// takes in reference of type and puts it into the pizza
    type.setIdNumber(newType.getIdNumber());
    type.setName(newType.getName());
    type.setPriceOffset(newType.getPriceOffset());
    type.setActiveState(newType.getActiveState());
}

void Pizza::setSauce(const PizzaSauce& newSauce) {  /// takes in reference of sauce and puts it into pizza
    sauce.setIdNumber(newSauce.getIdNumber());
    sauce.setName(newSauce.getName());
    sauce.setPriceCategory(newSauce.getPriceCategory());
    sauce.setActiveState(newSauce.getActiveState());
}

void Pizza::addToppings(Topping* arr) {
    for (int i = 0; arr[i].getIdNumber() != 0; i++) {
        if(arr[i].getIdNumber() != 0) {
            toppings[i].setIdNumber(arr[i].getIdNumber());
            toppings[i].setName(arr[i].getName());
            toppings[i].setPriceCategory(arr[i].getPriceCategory());
        }
    }
}

void Pizza::setTotalPrice(double newPrice) {
    totalPrice = newPrice;
}

void Pizza::setActiveState(bool newState) {
    isActive = newState;
}


///***************************************************************************************
/// Converts strings to a character array.
void Pizza::strToCharArr(string nameStr) {
    for(unsigned int i = 0; i < nameStr.size(); i++) {
        if(i == MAX_PIZZA_LENGTH -1) {
            break;
        }
        this->name[i] = nameStr.at(i);
    }
    this->name[nameStr.size()] = '\0';                   // Adds the esc.character after the end of the string.
    this->name[MAX_PIZZA_LENGTH - 1] = '\0';         // Adds the esc.character to the end of the charArray.
}
