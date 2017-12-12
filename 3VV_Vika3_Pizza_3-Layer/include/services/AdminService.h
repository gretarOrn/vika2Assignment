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

        void addPizza(string name, int sizeSelection, int typeSelection, int sauceSelection, int toppingSelection[], double totalPrice);
        void addPriceCategory(string name, int price);
        void addTopping(string name, int priceCat);
        void addExtra(string name, int prizeCat);
        void addSize(string name, int prizeCat, double toppingMult, double toppingOffset);
        void addSauce(string name, int prizeCat);
        void addType(string name, double priceOffset);
        void addLocation(string name, string address);

        bool validateName(string name);
        bool validatePriceCategory(int category);
        bool validatePrice(double price);

        bool validateTopping(int topping);

    private:

};

#endif // ADMINSERVICE_H
