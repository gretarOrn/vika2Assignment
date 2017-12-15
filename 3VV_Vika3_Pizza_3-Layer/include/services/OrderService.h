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

            static const int DELIVERY_COST = 1000;

        DataBase dataBase;
        SuperRepo repo;

        /// takes in a locationID and returns true, if there are any active orders at that location, otherwise returns false.
        bool validateOrdersInLocation(int locationID);
        /// calls by referance an instance of order and pizza and adds the pizza to the order.
        void addPizzaToOrder(Order& order, const Pizza& pizza);
        /// calls by referance an instance of order and extra and adds the extra to the order.
        void addExtraToOrder(Order& order, const Extra& extra);
        /// calls an order by referance and takes in delivery method , locationID, an address, a comment and information about the payment status and adds
        /// that information to the order.
        void addInfoToOrder(Order& order, bool delivery, int locationId, string address, string comment, bool payed);
        /// calls an order by referance and sends it to the repo to be added to the inactive order list. an instance of the order is still available in the active order file.
        void copyOrderToInactiveFile(const Order& order);
        /// takes in an order index and adds the corrosponding order from the active order file to the inactive order file.
        void moveOrderToInactiveFile(int orderIndex);
        /// takes in an order and sends it to the repo to be appended to the active order file.
        void saveOrder(const Order& order);
        /// takes in the complete list of active orders and saves it in it's entirety to the activeorders file.
        void saveOrders(Order* order);
        /// calls an order by referance, calculates the price of the order and returns it.
        double getPrice(Order& order);

        Extra addExtra(int extraNR);

    private:
        PizzaService pizzaService;
};

#endif // ORDERSERVICE_H
