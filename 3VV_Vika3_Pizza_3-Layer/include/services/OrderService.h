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

        DataBase dataBase;
        SuperRepo repo;

        bool validateOrdersInLocation(int locationID);
        void addPizzaToOrder(Order& order, const Pizza& pizza);
        void addExtraToOrder(Order& order, const Extra& extra);
        void addInfoToOrder(Order& order, bool delivery, int locationId, string address, string comment, bool payed);
        void copyOrderToInactiveFile(const Order& order);
        void moveOrderToInactiveFile(int orderIndex);
        void saveOrder(const Order& order);
        void saveOrders(Order* order);
        double getPrice(Order& order);

    private:
        PizzaService pizzaService;
};

#endif // ORDERSERVICE_H
