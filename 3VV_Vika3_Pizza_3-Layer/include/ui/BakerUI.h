#ifndef BAKERUI_H
#define BAKERUI_H

#include "DataBase.h"
#include "OrderService.h"
#include "ValidateService.h"
#include "SuperRepo.h"

#include <iostream>
#include <cstdlib>

class BakerUI
{
    public:
        BakerUI();
        void startUp();

    private:
        DataBase dataBase;
        ValidateService validate;
        OrderService orderService;
        SuperRepo repo;

        void displayLocations();
        int displayOrders(int locationID);
        void displayOrder(int orderID);
        void displayPizza(Pizza pizza);
        void displayExtra(Extra extra);
        int findOrderID(int orderSelection, int locationID);
};

#endif // BAKERUI_H
