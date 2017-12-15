#ifndef VALIDATESERVICE_H
#define VALIDATESERVICE_H

#include "DataBase.h"
#include "SuperRepo.h"

#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "InvalidPriceCategoryException.h"
#include "InvalidSizeException.h"
#include "InvalidTypeException.h"
#include "InvalidSauceException.h"
#include "InvalidToppingException.h"
#include "InvalidMultException.h"
#include "InvalidExtraException.h"
#include "InvalidPizzaException.h"
#include "InvalidActiveOrderException.h"
#include "InvalidLocationException.h"

class ValidateService
{
    public:
         ValidateService();

        DataBase dataBase;
        SuperRepo repo;
        /// all of these functions take in a variable and call a bool variable by reference. They check if the variable meets a certain criteria,
        /// if it does it changes the bool variable to true and returns, if it dosent it throws an error.
        void validateName(string name, bool& valid);
        void validatePrice(double price, bool& valid);
        void validatePriceCategory(int category, bool& valid);
        void validateMult(double toppingMult, bool& valid);

        void validateToppingSelection(int tempToppingSelection, bool& valid);
        void validatePizzaSelection(int pizzaSelection, bool& valid);
        void validateSizeSelection(int sizeSelection, bool& valid);
        void validateSauceSelection(int sauceSelection, bool& valid);
        void validateActiveOrderSelection(int orderSelection, int counter, bool& valid);
        void validateExtraSelection(int extraSelection, bool& valid);
        void validateTypeSelection(int typeSelection, bool& valid);
        void validateLocationSelection(int locationSelection, bool& valid);

        void validateOrdersInLocationBaker(int locationID, bool& valid);
        void validateOrdersInLocationDelivery(int locationID, bool& valid);

        ///calls by referance an instance of a number that's just been cin'd and checks if it is an int or double, if not it returns -1.
        void isInt(int& num);
        void isDouble(double& num);
    private:
};

#endif // VALIDATESERVICE_H
