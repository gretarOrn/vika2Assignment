#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "DataBase.h"
#include "SuperRepo.h"
#include "pizzaService.h"


class OrderService
{
    public:
        OrderService();
        virtual ~OrderService();
        void addToOrder(Order order);
        double getPrice(Order order);

    private:
        DataBase dataBase;
        PizzaService pizzaService;
};

#endif // ORDERSERVICE_H
