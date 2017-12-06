#include "SuperRepo.h"

SuperRepo::SuperRepo()
{
    //ctor
}

SuperRepo::~SuperRepo()
{
    //dtor
}

/// Extra
int SuperRepo::getExtraLines() const {
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

Extra* SuperRepo::readExtraFile() {
    ifstream fin;
    Extra* masterList = 0;
    fin.open("Extra.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Extra);
            fin.seekg(0, fin.beg);

            masterList = new Extra[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Extra)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToExtraFile(Extra extra) const {
    ofstream fout;
    fout.open("Extras.dat", ios::binary|ios::app);
    fout.write((char*)(&extra), sizeof(extra));
    fout.close();
}


/// Location
int SuperRepo::getLocationLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open("Locations.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Location);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Location* SuperRepo::readLocationFile() {
    ifstream fin;
    Location* masterList = 0;
    fin.open("Locations.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Location);
            fin.seekg(0, fin.beg);

            masterList = new Location[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Location)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToLocationFile(Location location) const {
    ofstream fout;
    fout.open("Locations.dat", ios::binary|ios::app);
    fout.write((char*)(&location), sizeof(Location));
    fout.close();
}


/// Order
int SuperRepo::getOrderLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open("ActiveOrders.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Order);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Order* SuperRepo::readOrderFile() {
    ifstream fin;
    Order* masterList = 0;
    fin.open("ActiveOrders.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Order);
            fin.seekg(0, fin.beg);

            masterList = new Order[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Order)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToOrderFile(Order order) const {
    ofstream fout;
    fout.open("ActiveOrders.dat", ios::binary|ios::app);
    fout.write((char*)(&order), sizeof(Order));
    fout.close();
}


/// Pizza
int SuperRepo::getPizzaLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open("PizzaMenu.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(Pizza);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

Pizza* SuperRepo::readPizzaFile() {
    ifstream fin;
    Pizza* masterList = 0;
    fin.open("PizzaMenu.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Pizza);
            fin.seekg(0, fin.beg);

            masterList = new Pizza[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Pizza)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToPizzaFile(Pizza pizza) const {
    ofstream fout;
    fout.open("PizzaMenu.dat", ios::binary|ios::app);
    fout.write((char*)(&pizza), sizeof(Pizza));
    fout.close();
}


/// Sauce
int SuperRepo::getSauceLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open("PizzaSauce.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(PizzaSauce);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

PizzaSauce* SuperRepo::readSauceFile() {
    ifstream fin;
    PizzaSauce* masterList = 0;
    fin.open("PizzaSauce.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(PizzaSauce);
            fin.seekg(0, fin.beg);

            masterList = new PizzaSauce[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(PizzaSauce)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToSauceFile(PizzaSauce sauce) const {
    ofstream fout;
    fout.open("PizzaSauce.dat", ios::binary|ios::app);
    fout.write((char*)(&sauce), sizeof(PizzaSauce));
    fout.close();
}


/// Size
int SuperRepo::getSizeLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open("PizzaSize.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(PizzaSize);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

PizzaSize* SuperRepo::readSizeFile() {
    ifstream fin;
    PizzaSize* masterList = 0;
    fin.open("PizzaSize.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(PizzaSize);
            fin.seekg(0, fin.beg);

            masterList = new PizzaSize[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(PizzaSize)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToSizeFile(PizzaSize size) const {
    ofstream fout;
    fout.open("PizzaSize.dat", ios::binary|ios::app);
    fout.write((char*)(&size), sizeof(PizzaSize));
    fout.close();
}


/// Type
int SuperRepo::getTypeLines() const {
    ifstream fin;
    int recordCount = 0;
    fin.open("PizzaType.dat", ios::binary);
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        recordCount = fin.tellg() / sizeof(PizzaType);
        fin.seekg(0, fin.beg);
    }
    fin.close();
    return recordCount;
}

PizzaType* SuperRepo::readTypeFile() {
    ifstream fin;
    PizzaType* masterList = 0;
    fin.open("PizzaType.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(PizzaType);
            fin.seekg(0, fin.beg);

            masterList = new PizzaType[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(PizzaType)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToTypeFile(PizzaType type) const {
    ofstream fout;
    fout.open("PizzaType.dat", ios::binary|ios::app);
    fout.write((char*)(&type), sizeof(PizzaType));
    fout.close();
}


/// Topping
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
    Topping* masterList = 0;
    fin.open("Toppings.dat");
        if(fin.is_open()) {
            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Topping);
            fin.seekg(0, fin.beg);

            masterList = new Topping[recordCount];

            fin.read((char*)(masterList), (recordCount * sizeof(Topping)));
        } else {
            cout << "Unable to open file.";
        }
    fin.close();
    return masterList;
}

void SuperRepo::writeToToppingFile(Topping topping) const {
    ofstream fout;
    fout.open("Toppings.dat", ios::binary|ios::app);
    fout.write((char*)(&topping), sizeof(Topping));
    fout.close();
}
