#ifndef SUPERREPO_H
#define SUPERREPO_H

#include "Extra.h"
#include "Location.h"
#include "Order.h"
#include "Pizza.h"
#include "PizzaSauce.h"
#include "PizzaSize.h"
#include "PizzaType.h"
#include "Topping.h"


class SuperRepo
{
    public:
        SuperRepo();
        virtual ~SuperRepo();

        /// Extra
        int getExtraLines() const;
        Extra* readExtraFile();
        void writeToExtraFile(Extra extra) const;

        /// Location
        int getLocationLines() const;
        Location* readLocationFile();
        void writeToLocationFile(Location location) const;

        /// Order
        int getOrderLines() const;
        Order* readOrderFile();
        void writeToOrderFile(Order order) const;

        /// Pizza
        int getPizzaLines() const;
        Pizza* readPizzaFile();
        void writeToPizzaFile(Pizza pizza) const;

        /// Sauce
        int getSauceLines() const;
        PizzaSauce* readSauceFile();
        void writeToSauceFile(PizzaSauce sauce) const;

        /// Size
        int getSizeLines() const;
        PizzaSize* readSizeFile();
        void writeToSizeFile(PizzaSize size) const;

        /// Type
        int getTypeLines() const;
        PizzaType* readTypeFile();
        void writeToTypeFile(PizzaType type) const;

        /// Topping
        int getToppingLines() const;
        Topping* readToppingFile();
        void writeToToppingFile(Topping topping) const;

    private:
};

#endif // SUPERREPO_H
