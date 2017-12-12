#ifndef SALESUI_H
#define SALESUI_H

#include "DataBase.h"
#include "OrderService.h"
#include "PizzaService.h"
#include "ExtraService.h"
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

        void createOrder();
        void addPizzaFromMenu(Order& order);
        void createCustomPizza(Order& order);
        void addExtraToOrder(Order& order);


        void printPizza(Pizza pizza, int counter);
        void printExtra(const Extra& extra);

        void displayPizzaMenu();
        void displaySizeList();
        void displayTypeList();
        void displaySauceList();
        void displayToppingList();
        void displayExtraList();
};

#endif // SALESUI_H
