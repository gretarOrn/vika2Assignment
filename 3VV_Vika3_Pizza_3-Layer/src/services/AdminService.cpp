#include "AdminService.h"

AdminService::AdminService()
{
    //ctor
}

void AdminService::addPriceCategory(string name, int price) {
    PriceList priceCat;
    dataBase.incrementPriceID();
    priceCat.setIdNumber(dataBase.getPriceID());
    priceCat.setName(name);
    priceCat.setPrice(price);
    priceCat.setActiveState(true);
    repo.writeToPriceFile(priceCat);
}

void AdminService::addTopping(string name, int priceCat) {
    Topping topping;
    dataBase.incrementToppingID();
    topping.setIdNumber(dataBase.getToppingID());
    topping.setName(name);
    topping.setPriceCategory(priceCat);
    topping.setActiveState(true);
    repo.writeToToppingFile(topping);
}

void AdminService::addExtra(string name, int priceCat) {
    Extra extra;
    dataBase.incrementExtraID();
    extra.setIdNumber(dataBase.getExtraID());
    extra.setName(name);
    extra.setPriceCategory(priceCat);
    extra.setActiveState(true);
    repo.writeToExtraFile(extra);
}

void AdminService::addSize(string name, int priceCat) {
    PizzaSize size;
    dataBase.incrementSizeID();
    size.setIdNumber(dataBase.getSizeID());
    size.setName(name);
    size.setPriceCategory(priceCat);
    size.setActiveState(true);
    repo.writeToSizeFile(size);
}

void AdminService::addSauce(string name, int priceCat) {
    PizzaSauce sauce;
    dataBase.incrementSauceID();
    sauce.setIdNumber(dataBase.getSauceID());
    sauce.setName(name);
    sauce.setPriceCategory(priceCat);
    sauce.setActiveState(true);
    repo.writeToSauceFile(sauce);
}

void AdminService::addType(string name, int priceCat) {
    PizzaType type;
    dataBase.incrementTypeID();
    type.setIdNumber(dataBase.getTypeID());
    type.setName(name);
    type.setPriceCategory(priceCat);
    type.setActiveState(true);
    repo.writeToTypeFile(type);
}

void AdminService::addLocation(string name, string address) {
    Location loc;
    dataBase.incrementLocationID();
    loc.setIdNumber(dataBase.getLocationID());
    loc.setName(name);
    loc.setAddress(address);
    loc.setActiveState(true);
    repo.writeToLocationFile(loc);
}


void AdminService::addPizza() {
    /*
    ofstream fout;

    Pizza pizza;

    int pizzaMasterSize = pizza.getLines();
    Pizza* pizzaMaster = pizza.readPizzaMenu();

    for(int i = 0; i < pizzaMasterSize; i++) {
         cout << pizzaMaster[i];
    }

    char userInput;

    do {
        cout << "Add an Pizza to the menu: " << endl;
        cin >> pizza;
        fout << pizza;
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
    */
}




bool AdminService::validateName(string name) {
    for(unsigned int i = 0; i < name.size(); i++) {
        if(isalpha(name.at(i))) {
            return true;
        }
    }
    return false;
}
bool AdminService::validatePriceCategory(int category) {
    if(category > 0 && category <= dataBase.getPriceID()) {
        return true;
    }
    return false;
}
bool AdminService::validatePrice(double price) {
    /// Needs double validation

    return true;
}
