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
    int counter = 0;
    while(counter < order.MAX_PIZZAS_ORDER) {
        // If a pizzas sauce has no name the pizza is created by the default constructor and is blank.
        if(order.getPizzas()[counter].getSauce().getName() == "") {
            order.getPizzas()[counter] = pizza;
            break;
        }
        counter++;
    }
    if(counter == order.MAX_PIZZAS_ORDER -1) {
        /// Throw maxPizzasPerOrderException();
        cout << "You have reached the maximum amount of pizzas in this order." << endl;
    }
}

void OrderService::addExtraToOrder(Order& order, const Extra& extra) {
    int counter = 0;
    while(counter < order.MAX_EXTRAS_ORDER) {
        // If a pizzas sauce has no name the pizza is created by the default constructor and is blank.
        if(order.getExtras()[counter].getName() == "") {
            order.getExtras()[counter] = extra;
            break;
        }
        counter++;
    }
    if(counter == order.MAX_EXTRAS_ORDER -1) {
        /// Throw maxExtrasPerOrderException();
        cout << "You have reached the maximum amount of extras in this order." << endl;
    }
}

void OrderService::addInfoToOrder(Order& order, bool delivery, int locationId, string address, string comment, bool payed) {
    dataBase.incrementOrderID();
    order.setOrderId(dataBase.getOrderID());
    order.setDeliveryMethod(delivery);
    order.setLocation(locationId);
    order.setAddress(address);
    order.setComment(comment);
    order.setPaymentStatus(payed);
    order.setOrderStatus(1);
}

void OrderService::copyOrderToInactiveFile(const Order& order) {
    repo.writeToInactiveOrderFile(order);
    dataBase.refreshInactiveOrder();
}

void OrderService::moveOrderToInactiveFile(int orderIndex) {
    Order* orderList = dataBase.activeOrderMaster;

    repo.writeAllButToActiveOrderFile(orderList, orderIndex);
    repo.writeToInactiveOrderFile(orderList[orderIndex]);

    dataBase.refreshActiveOrder();
    dataBase.refreshInactiveOrder();
}

void OrderService::saveOrder(const Order& order) {
    repo.writeToActiveOrderFile(order);
    dataBase.refreshActiveOrder();
}
void OrderService::saveOrders(Order* order) {
    repo.writeAllToActiveOrderFile(order);
    dataBase.refreshActiveOrder();
}

double OrderService::getPrice(Order& order) {
    double num = 0;
    PriceList* priceList = dataBase.priceMaster;
    for (int i = 0; order.getPizzas()[i].getSauce().getName() != ""; i++) {
        num += pizzaService.getPrice(order.getPizzas()[i]);
    }
    for (int i = 0; order.getExtras()[i].getName() != ""; i++) {
        num += priceList[order.getExtras()[i].getPriceCategory() - 1].getPrice();
    }
    if (order.isDelivered()) {
        num += DELIVERY_COST;
    }
    return num;
}

bool OrderService::validateOrdersInLocation(int locationID) {
    dataBase.refreshActiveOrder();
    Order* orderList = dataBase.activeOrderMaster;
    for (int i = 0; i < repo.getActiveOrderLines(); i++) {
        if (orderList[i].getLocationId() == locationID) {
            return true;
        }
    }
    return false;
}
Extra OrderService::addExtra(int extraNR) {
    Extra extra;
    DataBase database;
    extra.setIdNumber(database.extraMaster[extraNR - 1].getIdNumber());
    extra.setName(database.extraMaster[extraNR - 1].getName());
    extra.setPriceCategory(database.extraMaster[extraNR - 1].getPriceCategory());

    return extra;
}
