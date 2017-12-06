#include "DataBase.h"

DataBase::DataBase() {
    SuperRepo superRepo;
/*    superRepo.readToTopping();
    superRepo.readToPizza();
    superRepo.readToExtra();
    superRepo.readToSauce();
    superRepo.readToSize();
*/

}

DataBase::~DataBase() {
    //dtor
}
int DataBase::getExtraID() {
    return extraID;
}
int DataBase::getPizzaID() {
    return pizzaID;
}
int DataBase::getOrderID() {
    return orderID;
}
int DataBase::getSauceID() {
    return sauceID;
}
int DataBase::getSizeID() {
    return sizeID;
}
int DataBase::getToppingID() {
    return toppingID;
}
void DataBase::incrementExtraID() {
    extraID++;
}
void DataBase::incrementPizzaID() {
    pizzaID++;
}
void DataBase::incrementOrderID(){
    orderID++;
}
void DataBase::incrementSauceID() {
    sauceID++;
}
void DataBase::incrementSizeID() {
    sizeID++;
}
void DataBase::incrementToppingID() {
    toppingID++;
}


