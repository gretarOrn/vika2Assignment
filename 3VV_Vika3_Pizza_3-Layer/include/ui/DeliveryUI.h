#ifndef DELIVERYUI_H
#define DELIVERYUI_H

#include "DataBase.h"
#include "OrderService.h"

#include <iostream>
#include <cstdlib>

class DeliveryUI
{
    public:
        DeliveryUI();

        void startUp();

    private:
        DataBase dataBase;
        SuperRepo repo;
        OrderService orderService;

        void displayLocations();
        void displayOrders(int locationID);
        int findOrderID(int conter, int locationID);
};

#endif // DELIVERYUI_H
