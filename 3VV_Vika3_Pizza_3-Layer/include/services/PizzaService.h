#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "DataBase.h"


class PizzaService
{
    public:
        PizzaService();
        PizzaSize addSize(int sizeNR);
        PizzaType addType(int typeNR);
        PizzaSauce addSauce(int sauceNR);
        Topping* addTopping(int* arr, Pizza& pizza);
        void addPizzaToOrder(Pizza& pizza, const Topping& topping);
        double getPrice(Pizza pizza);


    private:
        DataBase dataBase;
};

#endif // PIZZASERVICE_H
