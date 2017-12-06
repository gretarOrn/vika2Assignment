#include "DataBase.h"

DataBase::DataBase() {
    extraMaster = repo.readExtraFile();
    locationMaster = repo.readLocationFile();
    activeOrderMaster = repo.readActiveOrderFile();
    inactiveOrderMaster = repo.readInactiveOrderFile();
    pizzaMaster = repo.readPizzaFile();
    sauceMaster = repo.readSauceFile();
    sizeMaster = repo.readSizeFile();
    typeMaster = repo.readTypeFile();
    priceMaster = repo.readPriceFile();
    toppingMaster = repo.readToppingFile();
}

DataBase::~DataBase() {
    if(extraMaster != 0) {
        delete[] extraMaster;
    } else {
        delete extraMaster;
    }
    if(locationMaster != 0) {
        delete[] locationMaster;
    } else {
        delete locationMaster;
    }
    if(activeOrderMaster != 0) {
        delete[] activeOrderMaster;
    } else {
        delete activeOrderMaster;
    }
    if(pizzaMaster != 0) {
        delete[] pizzaMaster;
    } else {
        delete pizzaMaster;
    }
    if(sauceMaster != 0) {
        delete[] sauceMaster;
    } else {
        delete sauceMaster;
    }
    if(sizeMaster != 0) {
        delete[] sizeMaster;
    } else {
        delete sizeMaster;
    }
    if(typeMaster != 0) {
        delete[] typeMaster;
    } else {
        delete typeMaster;
    }
    if(priceMaster != 0) {
        delete[] priceMaster;
    } else {
        delete priceMaster;
    }
    if(toppingMaster != 0) {
        delete[] toppingMaster;
    } else {
        delete toppingMaster;
    }
}
///***************************************************************************************
int DataBase::getExtraID() const{
    return extraID;
}
int DataBase::getLocationID() const{
    return locationID;
}
int DataBase::getOrderID() const{
    return orderID;
}
int DataBase::getPizzaID() const{
    return pizzaID;
}
int DataBase::getSauceID() const{
    return sauceID;
}
int DataBase::getSizeID() const{
    return sizeID;
}
int DataBase::getTypeID() const{
    return typeID;
}
int DataBase::getPriceID() const{
    return priceID;
}
int DataBase::getToppingID() const{
    return toppingID;
}
///***************************************************************************************
void DataBase::incrementExtraID() {
    extraID++;
}
void DataBase::incrementLocationID() {
    locationID++;
}
void DataBase::incrementOrderID() {
    orderID++;
}
void DataBase::incrementPizzaID() {
    pizzaID++;
}
void DataBase::incrementSauceID() {
    sauceID++;
}
void DataBase::incrementSizeID() {
    sizeID++;
}
void DataBase::incrementTypeID() {
    typeID++;
}
void DataBase::incrementPriceID() {
    priceID++;
}
void DataBase::incrementToppingID() {
    toppingID++;
}
///***************************************************************************************
void DataBase::setExtraID() {
    extraID = extraMaster[repo.getExtraLines() - 1].getIdNumber();
}
void DataBase::setLocationID() {
    //locationID = locationMaster[repo.getLocationLines() - 1].getIdNumber();
}
void DataBase::setOrderID() {
/*
    if(activeOrderMaster[repo.getActiveOrderLines() - 1].getIdNumber() > inactiveOrderMaster[repo.getInactiveOrderLines() - 1].getIdNumber()) {
        orderID = activeOrderMaster[repo.getActiveOrderLines() - 1].getIdNumber();
    } else {
        orderID = inactiveOrderMaster[repo.getInactiveOrderLines() - 1].getIdNumber();
    }
*/
}
void DataBase::setPizzaID() {
    pizzaID = pizzaMaster[repo.getPizzaLines() - 1].getIdNumber();
}
void DataBase::setSauceID() {
    sauceID = sauceMaster[repo.getSauceLines() - 1].getIdNumber();
}
void DataBase::setSizeID() {
    sizeID = sizeMaster[repo.getSizeLines() - 1].getIdNumber();
}
void DataBase::setTypeID() {
    typeID = typeMaster[repo.getTypeLines() - 1].getIdNumber();
}
void DataBase::setPriceID() {
    //priceID = priceIDMaster[repo.getPriceLines() - 1].getIdNumber();
}
void DataBase::setToppingID() {
    toppingID = toppingMaster[repo.getToppingLines() - 1].getIdNumber();
}

