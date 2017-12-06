#ifndef DATABASE_H
#define DATABASE_H

#include "Extra.h"
#include "Location.h"
#include "Order.h"
#include "Pizza.h"
#include "PizzaSauce.h"
#include "PizzaSize.h"
#include "PizzaType.h"
#include "PriceList.h"
#include "Topping.h"
#include "SuperRepo.h"

#include <vector>

class DataBase
{
    public:
        DataBase();
        ~DataBase();

        Extra* extraMaster;
        Pizza* pizzaMaster;
        PizzaSauce* sauceMaster;
        PizzaSize* sizeMaster;
        Topping* toppingMaster;
        int getExtraID();
        int getPizzaID();
        int getOrderID();
        int getSauceID();
        int getSizeID();
        int getToppingID();
        void incrementExtraID();
        void incrementPizzaID();
        void incrementOrderID();
        void incrementSauceID();
        void incrementSizeID();
        void incrementToppingID();




    private:
        int extraID;
        int pizzaID;
        int orderID;
        int sauceID;
        int sizeID;
        int toppingID;

};

#endif // DATABASE_H
