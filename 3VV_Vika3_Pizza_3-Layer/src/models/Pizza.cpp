#include "Pizza.h"

Pizza::Pizza() {
    idNumber = 0;
    name[0] = '\0';
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
/*
Topping Pizza::getTopping(int index) {
    return toppings[index];
}
*/
///***************************************************************************************

void Pizza::setIdNumber(int newIdNumber) {
    idNumber = newIdNumber;
}

void Pizza::setName(string newName) {
    strToCharArr(newName);
}

void Pizza::setSize(const PizzaSize& newSize) {
    size.setIdNumber(newSize.getIdNumber());
    size.setName(newSize.getName());
    size.setPriceCategory(newSize.getPriceCategory());
    size.setActiveState(newSize.getActiveState());
}

void Pizza::setType(const PizzaType& newType) {
    type.setIdNumber(newType.getIdNumber());
    type.setName(newType.getName());
    type.setPriceCategory(newType.getPriceCategory());
    type.setActiveState(newType.getActiveState());
}

void Pizza::setSauce(const PizzaSauce& newSauce) {
    sauce.setIdNumber(newSauce.getIdNumber());
    sauce.setName(newSauce.getName());
    sauce.setPriceCategory(newSauce.getPriceCategory());
    sauce.setActiveState(newSauce.getActiveState());
}

void Pizza::addTopping(const Topping& newTopping) {

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

/*
double Pizza::getPrice() const{
    double num = 0.0;
    for(int i = 0; toppings[i].getName() != ""; i++) {
        num += toppings[i].getPriceCategory() * 100;
    }
    num += 1000;
    return num;
}

int Pizza::getLines() const{
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

Pizza* Pizza::readPizzaMenu() {
    ifstream fin;
    Pizza* pizzaMaster = 0;
    fin.open("PizzaMenu.dat");
    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        int recordCount = fin.tellg() / sizeof(Pizza);
        fin.seekg(0, fin.beg);
        pizzaMaster = new Pizza[recordCount];

        fin.read((char*)(pizzaMaster), (recordCount * sizeof(Pizza)));
    } else {
        cout << "Unable to read the pizza menu." << endl;
    }
    fin.close();
    return pizzaMaster;
}


void Pizza::addSause() {
    cout << "Choose sauce: " << endl;

    int lines = sauce.getLines();
    PizzaSauce* sauceMaster = sauce.readFile();

    for(int i = 0; i < lines; i++) {
        if(sauceMaster[i].getActive()) {
            cout << sauceMaster[i];
        }
    }

    int userInput;
    cin >> userInput;
    sauce.setIdNumber(sauceMaster[userInput - 1].getIdNumber());
    sauce.setName(sauceMaster[userInput - 1].getName());
    sauce.setPriceCategory(sauceMaster[userInput - 1].getPriceCategory());
}

void Pizza::addTopping(Topping topping) {
    int counter = 0;
    while(counter < MAX_TOPPINGS_PIZZA) {
        if(toppings[counter].getName() == "") {
            toppings[counter].setName(topping.getName());
            toppings[counter].setPriceCategory(topping.getPriceCategory());
            break;
        }
        counter++;
    }
    if(counter == MAX_TOPPINGS_PIZZA - 1) {
        cout << "You have reached the maximum amount of toppings on this pizza." << endl;
    }
}

void Pizza::addToppings() {
    cout << endl << "Choose toppings: " << endl;

    DataBase data;
    SuperRepo repo;

    int lines = repo.getToppingLines();
    Topping* toppingMaster = repo.readToppingFile();

    for(int i = 0; i < lines; i++) {
        cout << (i + 1) << toppingMaster[i];
    }

    int userInput[MAX_TOPPINGS_PIZZA];
    int counter = 0;
    cout << "Select toppings, press 0 to stop." << endl;

    while(counter < MAX_TOPPINGS_PIZZA) {
        cin >> userInput[counter];
        if(userInput[counter] == 0) {
            break;
        }
        counter++;
    }

    for(int i = 0; i < counter; i++) {
        addTopping(toppingMaster[userInput[i] - 1]);
    }

}
*/

istream&  operator >> (istream& in, Pizza& pizza) {
    /*
    string nameStr;
    cout << "Enter pizza name: ";
    in >> ws;
    getline(in, nameStr);
    pizza.strToCharArr(nameStr);
    pizza.addSause();
    cout << "Enter pizza toppings: ";
    pizza.addToppings();
    */
    return in;
}

ostream&  operator << (ostream& out, const Pizza& pizza) {
    if(pizza.name[0] == '\0') {
        out << "Custom pizza: " << endl;
    } else {
        out << pizza.name << ": " << endl;
    }

    out << pizza.sauce;
    for(int i = 0; i < pizza.MAX_TOPPINGS_PIZZA; i++) {
        if(pizza.toppings[i].getName() != "") {
           out << pizza.toppings[i];
        }
    }
    //out << pizza.getPrice() << endl;

    return out;
}
/*
ifstream& operator >> (ifstream& fin, Pizza& pizza) {
    fin.open("PizzaMenu.dat", ios::binary);
    fin.read((char*)(&pizza), sizeof(Pizza));
    fin.close();
    return fin;
}

ofstream& operator << (ofstream& fout, const Pizza& pizza) {
    fout.open("PizzaMenu.dat", ios::binary|ios::app);
    fout.write((char*)(&pizza), sizeof(Pizza));
    fout.close();
    return fout;
}
*/
