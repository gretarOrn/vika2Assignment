#ifndef SALESUI_H
#define SALESUI_H

#include "DataBase.h"
#include "OrderService.h"
#include "PizzaService.h"
#include "ExtraService.h"
#include "AdminService.h" //Temp
#include "ValidateService.h"
#include <cstdlib>
#include <iomanip>

class SalesUI
{
    public:
        SalesUI();
        void startUp();

    private:
        DataBase dataBase;
        OrderService orderSer;
        PizzaService pizzaSer;
        ExtraService extraSer;
        AdminService adminSer;
        ValidateService validate;

        int defaultLocationId;

        void createOrder();
        void addPizzaFromMenu(Order& order);
        void createCustomPizza(Order& order);
        void addExtraToOrder(Order& order);

        void addInfo(Order& order);


        void printPizza(Pizza pizza, int counter);
        void printExtra(Order& order);

        void displayOrder(Order& order);
        void displayPizzaMenu();
        void displaySizeList();
        void displayTypeList();
        void displaySauceList();
        void displayToppingList();
        void displayExtraList();
        void displayLocationList();
};

#endif // SALESUI_H
