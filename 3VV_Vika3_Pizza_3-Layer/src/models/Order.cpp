#include "Order.h"

Order::Order()
{
    orderId = 0;
    name[0] = '\0';
    Pizza pizzas[MAX_PIZZAS_ORDER];
    Extra extras[MAX_EXTRAS_ORDER];
    delivery = false;
    locationId = 0;
    address[0] = '\0';
    totalPrice = 0.0;
    comment[0] = '\0';
    paymentStatus = false;
    orderStatus = 0;
    isActive = false;
}

///***************************************************************************************

int Order::getOrderId() const {
    return orderId;
}

string Order::getName() const {
    return name;
}

Pizza* Order::getPizzas()  {
    return pizzas;
}

Extra* Order::getExtras()  {
    return extras;
}

bool Order::isDelivered() const {
    return delivery;
}

int Order::getLocationId() const {
    return locationId;
}

string Order::getAddress() const {
    return address;
}

double Order::getTotalPrice() const {
    return totalPrice;
}

string Order::getComment() const {
    return comment;
}

bool Order::getPaymentStatus() const {
    return paymentStatus;
}

int Order::getOrderStatus() const {
    return orderStatus;
}

bool Order::getActiveState() const {
    return isActive;
}
///***************************************************************************************

void Order::setOrderId(int newOrderId) {
    orderId = newOrderId;
}

void Order::setName(string newName) {
    for(unsigned int i = 0; (i < newName.size()) && (i < MAX_NAME_LENGTH); i++) {
        name[i] = newName.at(i);
    }
    name[newName.size()] = '\0';
    name[MAX_NAME_LENGTH] = '\0';
}

void Order::addPizzas() {       //Kallar á fall í sevices

}

void Order::addExtras() {       //Kallar á fall í sevices
}

void Order::setDeliveryMethod(bool isDelivered) {
    delivery = isDelivered;
}

void Order::setLocation(int newLocationId) {
    locationId = newLocationId;
}

void Order::setAddress(string newAddress) {
    for(unsigned int i = 0; (i < newAddress.size()) && (i < MAX_ADDRESS_LENGTH); i++) {
        address[i] = newAddress.at(i);
    }
    address[newAddress.size()] = '\0';
    address[MAX_ADDRESS_LENGTH - 1] = '\0';
}

void Order::setTotalPrice(double newPrice) {
    totalPrice = newPrice;
}

void Order::setComment(string newComment) {
    for(unsigned int i = 0; (i < newComment.size()) && (i < MAX_COMMENT_LENGTH); i++) {
        comment[i] = newComment.at(i);
    }
    comment[newComment.size()] = '\0';
    comment[MAX_COMMENT_LENGTH - 1] = '\0';
}

void Order::setPaymentStatus(bool isPayed) {
    paymentStatus = isPayed;
}

void Order::setOrderStatus(int newOrderStatus) {
    orderStatus = newOrderStatus;
}

void Order::setActiveState(bool newState) {
    isActive = newState;
}
///***************************************************************************************

/*
double Order::getPrice() {
    double num = 0.0;
    for(int i = 0; pizzas[i].getSize() != 0; i++) {
        num += pizzas[i].getPrice();
    } if (_delMethod) {
        num += 1000;
    }
    return num;
}

void Order::pizzaOrders() {
    Topping topping;
    char cont;
    int i = 0;

    do {
        pizzas[i].addSause();
        pizzas[i].addToppings();

        cout <<"add another pizza to the order? (y/n):";
        cin >>cont;
        if(cont == 'y') {
            i++;
        }
    } while(cont == 'y');

    cout <<"Your pizzas: "<< endl;
    for(int j = 0; j <= i; j++) {
        cout << pizzas[j];
    }

}

void Order::setDelMethod() {
    char delivery;
    cout <<"pick up or delivery? (p/d): ";
    cin >> delivery;
    if(delivery == 'd') {
        _delMethod = delivery;
    }
}

void Order::setAddress() {
    if(_delMethod) {
        string address;
        cout <<"address: ";
        cin >>ws;
        getline(cin, address);
        for(unsigned int i = 0; i < address.size(); i++) {
            if(i == MAX_ADDRESS_LENGTH -1) {
                break;
            }
            _address[i] = address.at(i);
        }
        _address[address.size()] = '\0';
        _address[MAX_ADDRESS_LENGTH -1] = '\0';
    }
}

void Order::setComments() {
    char svar;
    string comment;
    cout <<"any comments?(y/n): ";
    cin >>svar;
    if(svar == 'y') {
        cout <<"comments :";
        cin >>ws;
        getline(cin, comment);
        for(unsigned int i = 0; i < comment.size(); i++) {
            if(i == MAX_COMMENT_LENGTH -1)
                break;
            _comments[i] = comment.at(i);
        }
        _comments[comment.size()] = '\0';
        _comments[MAX_COMMENT_LENGTH - 1] = '\0';
    }
}
*/
