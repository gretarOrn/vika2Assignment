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


    private:
};

#endif // PIZZASERVICE_H
