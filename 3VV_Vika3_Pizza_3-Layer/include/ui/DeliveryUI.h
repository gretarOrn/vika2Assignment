#ifndef DELIVERYUI_H
#define DELIVERYUI_H

#include "DataBase.h"

#include <iostream>
#include <cstdlib>

class DeliveryUI
{
    public:
        DeliveryUI();

        void startUp();

    private:
        DataBase dataBase;

        void displayLocations();
        void displayOrders(int locationID);
};

#endif // DELIVERYUI_H
