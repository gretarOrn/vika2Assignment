#include "Extra.h"

Extra::Extra()
{
    idNumber = 0;
    name[0] = '\0';
    priceCategory  = 0.0;
    isActive = false;
}

///***************************************************************************************

int Extra::getIdNumber() const{
    return idNumber;
}

string Extra::getName() const{
    return name;
}

double Extra::getPrice() const{
    return priceCategory;
}

bool Extra::getActiveState() const{
    return isActive;
}
/*
int Extra::getLines() const{
    ifstream fin;
    int recordCount = 0;
    fin.open("Extras.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Extra);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}
*/

///***************************************************************************************

void Extra::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void Extra::setName(string newName) {
    strToCharArr(newName);
}

void Extra::setPriceCategory(int newPriceCategory) {
    priceCategory = newPriceCategory;
}

void Extra::setActiveState(bool newState) {
    isActive = newState;
}

///***************************************************************************************
/// Converts strings to a character array.
void Extra::strToCharArr(string nameStr) {
    for(unsigned int i = 0; i < nameStr.size(); i++) {
        if(i == MAX_STRING_LENGTH -1) {
            break;
        }
        this->name[i] = nameStr.at(i);
    }
    this->name[nameStr.size()] = '\0';                   // Adds the esc.character after the end of the string.
    this->name[MAX_STRING_LENGTH - 1] = '\0';         // Adds the esc.character to the end of the charArray.
}
/*
Extra* Extra::readFile() {
    ifstream fin;
    Extra* extraMaster = 0;
    fin.open("Extras.dat");
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        int recordCount = fin.tellg() / sizeof(Extra);
        fin.seekg(0, fin.beg);
        extraMaster = new Extra[recordCount];

        fin.read((char*)(extraMaster), (recordCount * sizeof(Extra)));
    } else {
        cout << "Unable to read the extra list." << endl;
    }
    fin.close();
    return extraMaster;
}

*/
istream&  operator >> (istream& in, Extra& extra) {
    string nameStr;
    cout << "Enter extra's name: ";
    in >> ws;
    getline(in, nameStr);
    extra.strToCharArr(nameStr);
    cout << "Enter price:        ";
    in >> extra.priceCategory;
    return in;
}

ostream& operator << (ostream& out, const Extra& extra) {
    out << '\t' << setw(extra.MAX_STRING_LENGTH) << left << extra.name << " | Price: " << extra.priceCategory << endl;
    return out;
}
/*
ifstream& operator >> (ifstream& fin, Extra& extra) {
    fin.open("Extras.dat");
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        int recordCount = fin.tellg() / sizeof(Extra);
        fin.seekg(0, fin.beg);
        Extra* extraMaster = new Extra[recordCount];

        fin.read((char*)(extraMaster), (recordCount * sizeof(Extra)));
    } else {
        cout << "Unable to read the extra list." << endl;
    }
    fin.close();
    return fin;
}

ofstream& operator << (ofstream& fout, const Extra& extra) {
    fout.open("Extras.dat", ios::binary|ios::app);
    fout.write((char*)(&extra), sizeof(Extra));
    fout.close();
    return fout;
}
*/
