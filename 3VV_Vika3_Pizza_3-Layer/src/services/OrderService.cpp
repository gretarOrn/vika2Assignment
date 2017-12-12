#include "OrderService.h"

OrderService::OrderService()
{
    //ctor
}

OrderService::~OrderService()
{
    //dtor
}

void OrderService::addPizzaToOrder(Order& order, const Pizza& pizza) {

}

void OrderService::addInfoToOrder(Order& order, bool delivery, int locationId, string address, string comment) {
    dataBase.incrementOrderID();
    order.setOrderId(dataBase.getOrderID());
    order.setDeliveryMethod(delivery);
    order.setLocation(locationId);
    order.setAddress(address);
    order.setComment(comment);
    order.setOrderStatus(1);
}

void OrderService::saveOrder(Order order) {
    repo.writeToActiveOrderFile(order);
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
