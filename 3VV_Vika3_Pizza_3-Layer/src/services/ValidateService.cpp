#include "ValidateService.h"

ValidateService::ValidateService()
{
    //ctor
}

void ValidateService::validateName(string name, bool& valid) {
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
    if(category > 0 ) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidPriceException());
    }
}
void ValidateService::validatePrice(double price, bool& valid) {
    if(price > 0) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidOffsetException());
    }
}
void ValidateService::validateTopping(int topping, bool& valid) {
    if(topping > 0 && dataBase.getPriceID() >= topping) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidToppingException());
    }
}
void ValidateService::validateSize(int sizeSelection, bool& valid) {
    if(sizeSelection > 0 && dataBase.getPriceID() >= sizeSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSizeException());
    }
}
void ValidateService::validateType(int typeSelection, bool& valid) {
    if(typeSelection > 0 && dataBase.getPriceID() >= typeSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidTypeException());
    }
}
void ValidateService::validateSauce(int sauceSelection, bool& valid) {
    if(sauceSelection > 0 && dataBase.getPriceID() >= sauceSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSauceException());
    }
}
void ValidateService::validateMult(double toppingMult, bool& valid) {
    if(toppingMult > 0 && toppingMult <= 2) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidMultException());
    }
}
void ValidateService::validateExtra(int priceInput,bool& valid) {
    if(priceInput > 0 && dataBase.getPriceID() >= priceInput) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidExtraException());
    }
}
void ValidateService::validateToppingSelection(int tempToppingSelection ,bool& valid) {
    if(tempToppingSelection >= 0 && dataBase.getToppingID() >= tempToppingSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidToppingException());
    }
}
void ValidateService::validatePizzaSelection(int pizzaSelection, bool& valid) {
    if(pizzaSelection > 0 && dataBase.getPizzaID() >= pizzaSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidPizzaException());
    }
}
void ValidateService::validateActiveOrderSelection(int orderSelection, bool& valid) {
    if(orderSelection > 0 && repo.getActiveOrderLines() >= orderSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidActiveOrderException());
    }
}
void ValidateService::validateLocation(int locationSelection, bool& valid) {
    if(locationSelection > 0 && dataBase.getLocationID() >= locationSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidLocationException());
    }
}
void ValidateService::validateSizeSelection(int sizeSelection, bool& valid) {
    if(sizeSelection > 0 && dataBase.getSizeID() >= sizeSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSizeException());
    }
}
void ValidateService::validateTypeSelection(int typeSelection, bool& valid) {
    if(typeSelection > 0 && dataBase.getTypeID() >= typeSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidTypeException());
    }
}
void ValidateService::validateSauceSelection(int sauceSelection, bool& valid) {
    if(sauceSelection > 0 && dataBase.getSauceID() >= sauceSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidSauceException());
    }
}
void ValidateService::validateExtraSelection(int extraSelection, bool& valid) {
    if(extraSelection > 0 && dataBase.getExtraID() >= extraSelection) {
        valid = true;
        return;
    }
    if(!valid) {
        throw(InvalidExtraException());
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
