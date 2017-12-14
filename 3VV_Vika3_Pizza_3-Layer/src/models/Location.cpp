#include "Location.h"

Location::Location()
{
    idNumber = 0;
    name[0] = '\0';
    address[0] = '\0';
    isActive = false;
}

///***************************************************************************************

int Location::getIdNumber() const {
    return idNumber;
}

string Location::getName() const {
    return name;
}

string Location::getAddress() const {
    return address;
}

bool Location::getActiveState() const {
    return isActive;
}

///***************************************************************************************

void Location::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void Location::setName(string newName) {
    for(unsigned int i = 0; (i < newName.size()) && (i < MAX_STRING_LENGTH); i++) {
        name[i] = newName.at(i);
    }
    name[newName.size()] = '\0';                // Adds the esc.character after the end of the string.
    name[MAX_STRING_LENGTH - 1] = '\0';         // Adds the esc.character to the end of the charArray.
}

void Location::setAddress(string newAddress) {
    for(unsigned int i = 0; (i < newAddress.size()) && (i < MAX_ADDRESS_LENGTH); i++) {
        address[i] = newAddress.at(i);
    }
    address[newAddress.size()] = '\0';          // Adds the esc.character after the end of the string.
    address[MAX_ADDRESS_LENGTH - 1] = '\0';      // Adds the esc.character to the end of the charArray.

}

void Location::setActiveState(bool newState) {
    isActive = newState;
}

///***************************************************************************************
