#ifndef BAKERUI_H
#define BAKERUI_H

#include "DataBase.h"

#include <iostream>
#include <cstdlib>

class BakerUI
{
    public:
        BakerUI();

        void startUp();

    private:
        DataBase dataBase;

        void displayLocations();
        ///breyta exit conditioninu í startup UI?
        void displayOrders(int locationID);
        void displayOrder(int orderID);
        void displayPizza(Pizza pizza);
        void displayExtra(Extra extra);
};

#endif // BAKERUI_H
