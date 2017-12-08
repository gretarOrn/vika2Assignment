#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H

#include "SuperRepo.h"
#include "DataBase.h"

class AdminService
{
    public:
        AdminService();

        void addSauces(string name, int prizeCat);
        void addToppings(string name, int priceCat);
        void addPriceCategory(string name, int price);

        void addPizzas();
        void addExtras();

        SuperRepo repo;
        DataBase dataBase;

        bool validateName(string name);
        bool validatePriceCategory(int category);
        bool validatePrice(double price);

    private:

};

#endif // ADMINSERVICE_H
