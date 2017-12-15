#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H

#include "SuperRepo.h"
#include "DataBase.h"



class AdminService
{
    public:
        AdminService();

        DataBase dataBase;
        SuperRepo repo;
        /// Takes in a name, a size, type(base), a sauce , an array of toppings, and the total price and returns a pizza.
        Pizza addPizza(string name, int sizeSelection, int typeSelection, int sauceSelection, int toppingSelection[], double totalPrice);
        /// Takes a pizza to the repo to be filed as a type of pizza in the menu file
        void SavePizza(const Pizza& pizza);
        /// Takes in a name and a price for a new price category to be sent to the repo and placed in a file.
        void addPriceCategory(string name, int price);
        /// takes in a name and a price category for a new topping to be sent to the repo and placed in a file.
        void addTopping(string name, int priceCat);
        /// Takes in a name and a price category for a new topping to be sent to the repo and placed in a file.
        void addExtra(string name, int prizeCat);
        /// takes in a name, a price category, a topping multiplier and a topping offset for a new size to be sent to the repo and placed in a file.
        void addSize(string name, int prizeCat, double toppingMult, double toppingOffset);
        /// Takes in a name and a price category for a new sauce to be sent to the repo and placed in a file.
        void addSauce(string name, int prizeCat);
        /// takes in a name and a price offset for a new type(base) to be sent to the repo and placed in a file.
        void addType(string name, double priceOffset);
        /// takes in a name and an address of a new location to be sent to the repo and placed in a file.
        void addLocation(string name, string address);

    private:

};

#endif // ADMINSERVICE_H
