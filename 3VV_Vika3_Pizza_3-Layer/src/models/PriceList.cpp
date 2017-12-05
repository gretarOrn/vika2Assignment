#include "PriceList.h"

PriceList::PriceList()
{
    //ctor
}


/// Converts strings to a character array.
void PriceList::strToCharArr(string nameStr) {
    for(unsigned int i = 0; i < nameStr.size(); i++) {
        if(i == MAX_STRING_LENGTH -1) {
            break;
        }
        this->name[i] = nameStr.at(i);
    }
    this->name[nameStr.size()] = '\0';                   // Adds the esc.character after the end of the string.
    this->name[MAX_STRING_LENGTH - 1] = '\0';         // Adds the esc.character to the end of the charArray.
}

PriceList* PriceList::readFile() {
    ifstream fin;
    PriceList* priceMaster = 0;
    fin.open("PriceList.dat");
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        int recordCount = fin.tellg() / sizeof(PriceList);
        fin.seekg(0, fin.beg);
        priceMaster = new PriceList[recordCount];

        fin.read((char*)(priceMaster), (recordCount * sizeof(PriceList)));
    } else {
        cout << "Unable to read the price list." << endl;
    }
    fin.close();
    return priceMaster;
}

istream& operator >> (istream& in, PriceList& price) {
    return in;
}

ostream& operator << (ostream& out, const PriceList& price) {
    return out;
}

ifstream& operator >> (ifstream& fin, PriceList& price) {

    return fin;
}

ofstream& operator << (ofstream& fout, const PriceList& price) {
    fout.open("Price", ios::binary|ios::app);
    fout.write((char*)(&price), sizeof(PriceList));
    fout.close();
    return fout;
}
