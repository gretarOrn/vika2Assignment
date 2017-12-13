#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H

#include "SuperRepo.h"
#include "DataBase.h"

#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "InvalidSizeException.h"
#include "InvalidTypeException.h"
#include "InvalidSauceException.h"
#include "InvalidToppingException.h"
#include "InvalidMultException.h"
#include "InvalidOffsetException.h"
#include "InvalidExtraException.h"

class AdminService
{
    public:
        AdminService();

        DataBase dataBase;
        SuperRepo repo;

        void addPizza(string name, int sizeSelection, int typeSelection, int sauceSelection, int toppingSelection[], double totalPrice);
        void addPriceCategory(string name, int price);
        void addTopping(string name, int priceCat);
        void addExtra(string name, int prizeCat);
        void addSize(string name, int prizeCat, double toppingMult, double toppingOffset);
        void addSauce(string name, int prizeCat);
        void addType(string name, double priceOffset);
        void addLocation(string name, string address);

        void validateName(string name, bool& valid);
        void validatePriceCategory(int category, bool& valid);
        void validateSize(int sizeSelection, bool& valid);
        void validateType(int typeSelection, bool& valid);
        void validateSauce(int sauceSelection, bool& valid);
        void validateMult(double toppingMult, bool& valid);
        void validatePrice(double price, bool& valid);
        void validateExtra(int priceInput,bool& valid);
        void validateToppingSelection(int tempToppingSelection,bool& valid);

        void validateTopping(int topping, bool& valid);

        void isInt(int& num);
        void isDouble(double& num);

    private:

};

#endif // ADMINSERVICE_H
