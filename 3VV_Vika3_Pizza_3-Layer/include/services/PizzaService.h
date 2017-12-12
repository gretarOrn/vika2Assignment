#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "DataBase.h"


class PizzaService
{
    public:
        PizzaService();
        PizzaSauce addSauce(int sauceNR);
        Topping* addTopping(int* arr, Pizza& pizza);
        PizzaSize addSize(int sizeNR);
        PizzaType addType(int typeNR);
        double getPrice(Pizza pizza);


    private:
        DataBase dataBase;
};

#endif // PIZZASERVICE_H
