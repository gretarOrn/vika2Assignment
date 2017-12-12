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

double OrderService::getPrice(Order order) {
    double num = 0;
    PriceList* priceList = dataBase.priceMaster;
    for (int i = 0; order.getPizzas()[i].getSauce().getName() != ""; i++) {
        num += pizzaService.getPrice(order.getPizzas()[i]);
    }
    for (int i = 0; order.getExtras()[i].getName() != ""; i++) {
        num += priceList[order.getExtras()[i].getPriceCategory() - 1].getPrice();
    }
    if (order.isDelivered()) {
        num += 800;
    }
    return num;
}
