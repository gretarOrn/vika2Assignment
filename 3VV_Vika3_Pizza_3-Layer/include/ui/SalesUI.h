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
        DataBase data;
        OrderService orderSer;
        PizzaService pizzaSer;

        void createOrder();
        void printPizza(Pizza pizza, int counter);
        void printExtra(const Extra& extra);

        void displaySizeList();
        void displayTypeList();
        void displaySauceList();
        void displayToppingList();
        void displayExtraList();
};

#endif // SALESUI_H
