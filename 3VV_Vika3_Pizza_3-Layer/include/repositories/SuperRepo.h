#ifndef SUPERREPO_H
#define SUPERREPO_H

#include "Extra.h"
#include "Location.h"
#include "Order.h"
#include "Pizza.h"
#include "PizzaSauce.h"
#include "PizzaSize.h"
#include "PizzaType.h"
#include "PriceList.h"
#include "Topping.h"


class SuperRepo
{
    public:
        SuperRepo();
        virtual ~SuperRepo();

        /// Extra
        int getExtraLines() const;
        Extra* readExtraFile();
        void writeToExtraFile(const Extra& extra);

        /// Location
        int getLocationLines() const;
        Location* readLocationFile();
        void writeToLocationFile(const Location& location);

        /// ActiveOrder
        int getActiveOrderLines() const;
        Order* readActiveOrderFile();
        void writeToActiveOrderFile(const Order& order);
        void writeAllButToActiveOrderFile(Order* order, int lineNr);

        /// InactiveOrder
        int getInactiveOrderLines() const;
        Order* readInactiveOrderFile();
        void writeToInactiveOrderFile(const Order& order);

        /// Pizza
        int getPizzaLines() const;
        Pizza* readPizzaFile();
        void writeToPizzaFile(const Pizza& pizza);

        /// Sauce
        int getSauceLines() const;
        PizzaSauce* readSauceFile();
        void writeToSauceFile(const PizzaSauce& sauce);

        /// Size
        int getSizeLines() const;
        PizzaSize* readSizeFile();
        void writeToSizeFile(const PizzaSize& size);

        /// Type
        int getTypeLines() const;
        PizzaType* readTypeFile();
        void writeToTypeFile(const PizzaType& type);

        /// Price
        int getPriceLines() const;
        PriceList* readPriceFile();
        void writeToPriceFile(const PriceList& price);

        /// Topping
        int getToppingLines() const;
        Topping* readToppingFile();
        void writeToToppingFile(const Topping& topping);

    private:
};

#endif // SUPERREPO_H
