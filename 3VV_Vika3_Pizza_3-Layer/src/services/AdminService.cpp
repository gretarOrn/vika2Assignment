#include "AdminService.h"

AdminService::AdminService()
{
    //ctor
}
void AdminService::addPizza(string name, int sizeSelection, int typeSelection, int sauceSelection, int* toppingSelection) {
    Pizza pizza;
    dataBase.incrementPizzaID();
    pizza.setIdNumber(dataBase.getPizzaID());
    pizza.setName(name);
    pizza.setSize(dataBase.sizeMaster[sizeSelection - 1]);
    pizza.setType(dataBase.typeMaster[typeSelection - 1]);
    pizza.setSauce(dataBase.sauceMaster[sauceSelection - 1]);
    Topping* toppings = pizza.getToppings();
    for(int i = 0; i < pizza.MAX_TOPPINGS_PIZZA; i++) {
        if(toppingSelection[i] != 0) {
            toppings[i].setIdNumber(dataBase.toppingMaster[toppingSelection[i] -1].getIdNumber());
            toppings[i].setName(dataBase.toppingMaster[toppingSelection[i] -1].getName());
            toppings[i].setPriceCategory(dataBase.toppingMaster[toppingSelection[i] -1].getPriceCategory());
            toppings[i].setActiveState(dataBase.toppingMaster[toppingSelection[i] -1].getActiveState());
        }
    }
    repo.writeToPizzaFile(pizza);
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

void AdminService::addType(string name, double priceOfset) {
    PizzaType type;
    dataBase.incrementTypeID();
    type.setIdNumber(dataBase.getTypeID());
    type.setName(name);
    type.setPriceOfset(priceOfset);
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




/*
void AdminService::editTopping(int newIdNumber, string newName, int newPriceCat, bool newState) {
    Topping topping;
    topping.setIdNumber(newIdNumber);
    topping.setName(newName);
    topping.setPriceCategory(newPriceCat);
    topping.setActiveState(newState);
    SuperRepo repo;
    //repo.insertIntoToppingFile(topping, newIdNumber);
}
*/


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

bool AdminService::validateTopping(int topping) {
    if(topping > 0 && topping <= dataBase.getToppingID()) {
        return true;
    }
    return false;
}
