#include "ValidateService.h"

ValidateService::ValidateService()
{
    //ctor
}

void ValidateService::validateName(string name, bool& valid) {
    valid = false;
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
void ValidateService::validatePriceCategory(int category, bool& valid) {
    valid = false;
    if(0 < category ) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidPriceException());
    }
}
void ValidateService::validatePrice(double price, bool& valid) {
    valid = false;
    if(0 < price) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidOffsetException());
    }
}
void ValidateService::validateTopping(int topping, bool& valid) {
    valid = false;
    if(0 < topping && topping <= dataBase.getPriceID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidToppingException());
    }
}
void ValidateService::validateSize(int sizeSelection, bool& valid) {
    valid = false;
    if(0 < sizeSelection && sizeSelection <= dataBase.getPriceID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSizeException());
    }
}
void ValidateService::validateType(int typeSelection, bool& valid) {
    valid = false;
    if(0 < typeSelection && typeSelection <= dataBase.getPriceID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidTypeException());
    }
}
void ValidateService::validateSauce(int sauceSelection, bool& valid) {
    valid = false;
    if(0 < sauceSelection && sauceSelection <= dataBase.getPriceID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSauceException());
    }
}
void ValidateService::validateMult(double toppingMult, bool& valid) {
    valid = false;
    if(0 < toppingMult && toppingMult <= 3) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidMultException());
    }
}
void ValidateService::validateExtra(int priceInput,bool& valid) {
    valid = false;
    if(0 < priceInput && priceInput <= dataBase.getPriceID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidExtraException());
    }
}
void ValidateService::validateToppingSelection(int tempToppingSelection ,bool& valid) {
    valid = false;
    if(0 <= tempToppingSelection && tempToppingSelection <= dataBase.getToppingID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidToppingException());
    }
}
void ValidateService::validatePizzaSelection(int pizzaSelection, bool& valid) {
    valid = false;
    if(0 < pizzaSelection && pizzaSelection <= dataBase.getPizzaID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidPizzaException());
    }
}
void ValidateService::validateActiveOrderSelection(int orderSelection, int counter, bool& valid) {
    valid = false;
    if(0 < orderSelection && orderSelection <= counter) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidActiveOrderException());
    }
}
void ValidateService::validateLocation(int locationSelection, bool& valid) {
    valid = false;
    if(0 < locationSelection && locationSelection <= dataBase.getLocationID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidLocationException());
    }
}
void ValidateService::validateSizeSelection(int sizeSelection, bool& valid) {
    valid = false;
    if(0 < sizeSelection && sizeSelection <= dataBase.getSizeID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSizeException());
    }
}
void ValidateService::validateTypeSelection(int typeSelection, bool& valid) {
    valid = false;
    if(0 < typeSelection && typeSelection <= dataBase.getTypeID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidTypeException());
    }
}
void ValidateService::validateSauceSelection(int sauceSelection, bool& valid) {
    valid = false;
    if(0 < sauceSelection && sauceSelection <= dataBase.getSauceID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSauceException());
    }
}
void ValidateService::validateExtraSelection(int extraSelection, bool& valid) {
    valid = false;
    if(0 < extraSelection && extraSelection <= dataBase.getExtraID()) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidExtraException());
    }
}
void ValidateService::validateOrdersInLocationBaker(int locationID, bool& valid) {
    valid = false;
    dataBase.refreshActiveOrder();
    Order* orderList = dataBase.activeOrderMaster;
    for (int i = 0; i < repo.getActiveOrderLines(); i++) {
        if (orderList[i].getLocationId() == locationID) {
            if (orderList[i].getOrderStatus() == 1 || orderList[i].getOrderStatus() == 2) {
                valid = true;
                return;
            }
        }
    }
    if (!valid) {
        throw (InvalidActiveOrderException());
    }
}
void ValidateService::validateOrdersInLocationDelivery(int locationID, bool& valid) {
    valid = false;
    dataBase.refreshActiveOrder();
    Order* orderList = dataBase.activeOrderMaster;
    for (int i = 0; i < repo.getActiveOrderLines(); i++) {
        if (orderList[i].getLocationId() == locationID) {
            valid = true;
            return;
        }
    }
    if (!valid) {
        throw (InvalidActiveOrderException());
    }
}
void ValidateService::isInt(int& num) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        num = -1;
    }
}
void ValidateService::isDouble(double& num) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        num = -1;
    }
}
