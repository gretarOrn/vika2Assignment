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

istream&  operator >> (istream& in, Topping& topping) {
    string nameStr;
    cout << "Enter topping name:   ";
    in >> ws;
    getline(in, nameStr);
    topping.strToCharArr(nameStr);
    cout << "Enter price category: ";
    in >> topping.priceCategory;
    topping.setActiveState(true);
    return in;
}

ostream& operator << (ostream& out, const Topping& topping) {
    out << '\t' << setw(topping.MAX_STRING_LENGTH) << left << topping.name << " | Price category: " << topping.priceCategory << endl;
    return out;
}
/*
ifstream& operator >> (ifstream& fin, Topping& topping) {
    fin.open("Toppings.dat");
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        int recordCount = fin.tellg() / sizeof(Topping);
        fin.seekg(0, fin.beg);
        Topping* toppingsMaster = new Topping[recordCount];

        fin.read((char*)(toppingsMaster), (recordCount * sizeof(Topping)));
    } else {
        cout << "Unable to read the topping list." << endl;
    }
    fin.close();
    return fin;
}

ofstream& operator << (ofstream& fout, const Topping& topping) {
    fout.open("Toppings.dat", ios::binary|ios::app);
    fout.write((char*)(&topping), sizeof(Topping));
    fout.close();
    return fout;
}
*/
