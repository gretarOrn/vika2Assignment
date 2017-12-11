#include "OrderService.h"

OrderService::OrderService()
{
    //ctor
}

OrderService::~OrderService()
{
    //dtor
}
void OrderService::addToOrder(Order order) {
    SuperRepo superRepo;
    superRepo.writeToActiveOrderFile(order);


}

