#include "PizzaSauce.h"

PizzaSauce::PizzaSauce()
{
    idNumber = 0;
    name[0] = '\0';
    priceCategory = 0;
    active = false;
}

int PizzaSauce::getIdNumber() const{
    return idNumber;
}

string PizzaSauce::getName() const{
    return name;
}

int PizzaSauce::getPriceCategory() const{
    return priceCategory;
}

/*double PizzaSauce::getPrice() const {

} */

bool PizzaSauce::getActiveState() const{
    return active;
}

void PizzaSauce::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void PizzaSauce::setName(string newName) {
    strToCharArr(newName);
}

void PizzaSauce::setPriceCategory(int newPriceCatagory) {
    priceCategory = newPriceCatagory;
}

void PizzaSauce::setActiveState(bool newState) {
    active = newState;
}

/// Converts strings to a character array.
void PizzaSauce::strToCharArr(string nameStr) {
    for(unsigned int i = 0; i < nameStr.size(); i++) {
        if(i == MAX_STRING_LENGTH -1) {
            break;
        }
        this->name[i] = nameStr.at(i);
    }
    this->name[nameStr.size()] = '\0';                   // Adds the esc.character after the end of the string.
    this->name[MAX_STRING_LENGTH - 1] = '\0';         // Adds the esc.character to the end of the charArray.
}


istream& operator >> (istream& in, PizzaSauce& sauce) {
/*    sauce.idNumber = (sauce.getLines() + 1);
    string nameStr;
    cout << "Enter sauce name: ";
    in >> ws;
    getline(in, nameStr);
    sauce.strToCharArr(nameStr);
    cout << "Enter price category: ";
    in >> sauce.priceCategory;
    sauce.active = true; */
    return in;
}

ostream& operator << (ostream& out, const PizzaSauce& sauce) {
    out << sauce.idNumber << ") " <<  '\t' << setw(sauce.MAX_STRING_LENGTH) << left << sauce.name << " | Price category: " << sauce.priceCategory << endl;
    return out;
}
