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


class DataBase
{
    public:
        DataBase();
        ~DataBase();

        SuperRepo repo;

        Extra* extraMaster;
        Location* locationMaster;
        Order* activeOrderMaster;
        Order* inactiveOrderMaster;
        Pizza* pizzaMaster;
        PizzaSauce* sauceMaster;
        PizzaSize* sizeMaster;
        PizzaType* typeMaster;
        PriceList* priceMaster;
        Topping* toppingMaster;

        int getExtraID() const;
        int getLocationID() const;
        int getOrderID() const;
        int getPizzaID() const;
        int getSauceID() const;
        int getSizeID() const;
        int getTypeID() const;
        int getPriceID() const;
        int getToppingID() const;

        void incrementExtraID();
        void incrementLocationID();
        void incrementOrderID();
        void incrementPizzaID();
        void incrementSauceID();
        void incrementSizeID();
        void incrementTypeID();
        void incrementPriceID();
        void incrementToppingID();

        void refreshExtra();
        void refreshLocation();
        void refreshActiveOrder();
        void refreshInactiveOrder();
        void refreshPizza();
        void refreshSauce();
        void refreshSize();
        void refreshType();
        void refreshPrice();
        void refreshTopping();



    private:
        int extraID;
        int locationID;
        int orderID;
        int pizzaID;
        int sauceID;
        int sizeID;
        int typeID;
        int priceID;
        int toppingID;

        void setExtraID();
        void setLocationID();
        void setOrderID();
        void setPizzaID();
        void setSauceID();
        void setSizeID();
        void setTypeID();
        void setPriceID();
        void setToppingID();
};

#endif // DATABASE_H
