#include "AdminService.h"

AdminService::AdminService()
{
    //ctor
}
void AdminService::addPizza(string name, int sizeSelection, int typeSelection, int sauceSelection, int* toppingSelection, double totalPrice) {
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
    pizza.setTotalPrice(totalPrice);
    pizza.setActiveState(true);
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

void AdminService::addSize(string name, int priceCat, double toppingMult, double toppingOffset) {
    PizzaSize size;
    dataBase.incrementSizeID();
    size.setIdNumber(dataBase.getSizeID());
    size.setName(name);
    size.setPriceCategory(priceCat);
    size.setToppingMult(toppingMult);
    size.setToppingOffset(toppingOffset);
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

void AdminService::addType(string name, double priceOffset) {
    PizzaType type;
    dataBase.incrementTypeID();
    type.setIdNumber(dataBase.getTypeID());
    type.setName(name);
    type.setPriceOffset(priceOffset);
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


void AdminService::validateName(string name, bool& valid) {
    for(unsigned int i = 0; i < name.size(); i++) {
        if(isalpha(name.at(i))) {
            valid = true;
            return;
        }
    }
    if(!valid) {
        throw(InvalidNameException());
    }
}
void AdminService::validatePriceCategory(int category, bool& valid) {
    if(category > 0 ) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidPriceException());
    }
}
void AdminService::validatePrice(double price, bool& valid) {
    if(price > 0) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidOffsetException());
    }
}

void AdminService::validateTopping(int topping, bool& valid) {
    if(topping > 0 && dataBase.getPriceID() >= topping) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidToppingException());
    }
}
void AdminService::validateSize(int sizeSelection, bool& valid) {
    if(sizeSelection > 0) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSizeException());
    }
}
void AdminService::validateType(int typeSelection, bool& valid) {
    if(typeSelection > 0 && dataBase.getPriceID() >= typeSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidTypeException());
    }
}
void AdminService::validateSauce(int sauceSelection, bool& valid) {
    if(sauceSelection > 0 && dataBase.getPriceID() >= sauceSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSauceException());
    }
}
void AdminService::validateMult(double toppingMult, bool& valid) {
    if(toppingMult > 0 && toppingMult <= 2) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidMultException());
    }
}
void AdminService::validateExtra(int priceInput,bool& valid) {
    if(priceInput > 0 && dataBase.getPriceID() >= priceInput) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidExtraException());
    }
}
void AdminService::validateToppingSelection(int tempToppingSelection ,bool& valid) {
    if(tempToppingSelection > 0 && dataBase.getToppingID() >= tempToppingSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidToppingException());
    }
}
void AdminService::isInt(int& num) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        num = -1;
    }
}
void AdminService::isDouble(double& num) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        num = -1;
    }
}
