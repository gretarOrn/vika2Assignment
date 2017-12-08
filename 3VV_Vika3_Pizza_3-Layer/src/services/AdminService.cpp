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

void AdminService::addToppings(string name, int priceCat) {
    Topping topping;
    dataBase.incrementToppingID();
    topping.setIdNumber(dataBase.getToppingID());
    topping.setName(name);
    topping.setPriceCategory(priceCat);
    topping.setActiveState(true);
    repo.writeToToppingFile(topping);
}

void AdminService::addSauces(string name, int priceCat) {
    PizzaSauce sauce;
    dataBase.incrementSauceID();
    sauce.setIdNumber(dataBase.getSauceID());
    sauce.setName(name);
    sauce.setPriceCategory(priceCat);
    sauce.setActiveState(true);
    repo.writeToSauceFile(sauce);
}


void AdminService::addPizzas() {
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

void AdminService::addExtras() {
/*
    ofstream fout;

    Extra extra;

    int extraMasterSize = extra.getLines();
    Extra* extraMaster = extra.readFile();

    for(int i = 0; i < extraMasterSize; i++) {
        cout << (i + 1) << ")" << extraMaster[i];
    }

    char userInput;

    do {
        userInput = 'n';
        cout << "Add an extra: " << endl;
        cin >> extra;
        fout << extra;
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
