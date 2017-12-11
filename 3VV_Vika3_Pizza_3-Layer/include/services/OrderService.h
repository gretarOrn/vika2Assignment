#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "DataBase.h"
#include "SuperRepo.h"


class OrderService
{
    public:
        OrderService();
        virtual ~OrderService();
        void addToOrder(Order order);

    private:
};

#endif // ORDERSERVICE_H
