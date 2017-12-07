#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H

#include "SuperRepo.h"
#include "DataBase.h"

class AdminService
{
    public:
        AdminService();
        virtual ~AdminService();

        void addSauces(string name, int prizeCat);
        void addToppings(string name, int priceCat);
        void addPriceCategory(string name, int price);
        void addPizzas();
        void addExtras();

        SuperRepo repo;
        DataBase dataBase;
        int sauceListSize();
        int toppingListSize();
        int priceListSize();

        bool validateName(string name);
        bool validatePrizeCategory(int cat);

    private:

};

#endif // ADMINSERVICE_H
