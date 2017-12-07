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

bool PizzaSauce::getActive() const{
    return active;
}

/*int PizzaSauce::getLines() const{
    ifstream fin;
    int recordCount = 0;
    fin.open("PizzaSauce.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(PizzaSauce);
    }
    fin.close();
    return recordCount;
}*/

PizzaSauce* PizzaSauce::readFile() {
    ifstream fin;
    PizzaSauce* sauceMaster = 0;
    fin.open("PizzaSauce.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        int recorndCount = fin.tellg() / sizeof(PizzaSauce);
        fin.seekg(0, fin.beg);
        sauceMaster = new PizzaSauce[recorndCount];

        fin.read((char*)(sauceMaster), (recorndCount * sizeof(PizzaSauce)));
    } else {
        cout << "Unable to read the sauce list." << endl;
    }
    fin.close();
    return sauceMaster;
}

void PizzaSauce::writeToFile() const{

}

void PizzaSauce::displaySauce() const{
    ifstream fin;
    PizzaSauce* sauceMaster = 0;
    fin.open("PizzaSauce.dat", ios::binary);
    int recordCount = 0;
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(PizzaSauce);
        fin.seekg(0, fin.beg);
        sauceMaster = new PizzaSauce[recordCount];

        fin.read((char*)(sauceMaster), (recordCount * sizeof(PizzaSauce)));
    } else {
        cout << "Unable to read the sauce list." << endl;
    }
    fin.close();

    for(int i = 0; i < recordCount; i++) {
        if(sauceMaster[i].active) {
            cout << sauceMaster[i];
        }
    }
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

void PizzaSauce::setActive(bool newState) {
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

ifstream& operator >> (ifstream& fin, PizzaSauce& sauce) {
    return fin;
}

ofstream& operator << (ofstream& fout, const PizzaSauce& sauce) {
    fout.open("PizzaSauce.dat", ios::binary|ios::app);
    fout.write((char*)(&sauce), sizeof(PizzaSauce));
    fout.close();
    return fout;
}
