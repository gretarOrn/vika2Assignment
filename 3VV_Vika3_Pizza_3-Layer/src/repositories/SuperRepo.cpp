#include "SuperRepo.h"

SuperRepo::SuperRepo()
{
    //ctor
}

SuperRepo::~SuperRepo()
{
    //dtor
}

int SuperRepo::getToppingLines() const{
    ifstream fin;
    int recordCount = 0;
    fin.open("Toppings.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Topping);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Topping* SuperRepo::readToppingFile() {
    ifstream fin;
    Topping* toppingsMaster = 0;
    fin.open("Toppings.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Topping);
            fin.seekg(0, fin.beg);

            toppingsMaster = new Topping[recordCount];

            fin.read((char*)(toppingsMaster), (recordCount * sizeof(Topping)));
        } else {

        }
    fin.close();
    return toppingsMaster;
}

void SuperRepo::writeToToppingFile(Topping topping) const {
    ofstream fout;
    fout.open("Toppings.dat", ios::binary|ios::app);
    fout.write((char*)(&topping), sizeof(Topping));
    fout.close();
}

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
