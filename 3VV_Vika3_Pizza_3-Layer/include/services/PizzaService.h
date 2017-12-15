#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "DataBase.h"


class PizzaService
{
    public:
        PizzaService();

       /// takes in the position of ingredients of ingredients in their respective files, and adds them to an instance of pizza.
        Pizza createPizza(int sizeSelction, int typeSelction, int sauceSelction, int toppingSelction[]);

        /// takes in an instance of pizza and returns its price.
        double getPrice(Pizza pizza);


    private:
        DataBase dataBase;
};

#endif // PIZZASERVICE_H
