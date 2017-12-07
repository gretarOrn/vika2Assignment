#include "DataBase.h"

DataBase::DataBase() {
    extraMaster = repo.readExtraFile();
    setExtraID();
    locationMaster = repo.readLocationFile();
    setLocationID();
    activeOrderMaster = repo.readActiveOrderFile();
    inactiveOrderMaster = repo.readInactiveOrderFile();
    setOrderID();
    pizzaMaster = repo.readPizzaFile();
    setPizzaID();
    sauceMaster = repo.readSauceFile();
    setSauceID();
    sizeMaster = repo.readSizeFile();
    setSizeID();
    typeMaster = repo.readTypeFile();
    setTypeID();
    priceMaster = repo.readPriceFile();
    setPriceID();
    toppingMaster = repo.readToppingFile();
    setToppingID();
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
    locationID = locationMaster[repo.getLocationLines() - 1].getIdNumber();
}
void DataBase::setOrderID() {
    if(activeOrderMaster[repo.getActiveOrderLines() - 1].getOrderId() > inactiveOrderMaster[repo.getInactiveOrderLines() - 1].getOrderId()) {
        orderID = activeOrderMaster[repo.getActiveOrderLines() - 1].getOrderId();
    } else {
        orderID = inactiveOrderMaster[repo.getInactiveOrderLines() - 1].getOrderId();
    }
}
void DataBase::setPizzaID() {
    if (pizzaMaster == 0) {
        pizzaID = 1;
    } else {
        pizzaID = pizzaMaster[repo.getPizzaLines() - 1].getIdNumber();
    }
}
void DataBase::setSauceID() {
    if (sauceMaster == 0) {
        sauceID = 1;
    } else {
        sauceID = sauceMaster[repo.getSauceLines() - 1].getIdNumber();
    }
}
void DataBase::setSizeID() {
    if (sizeMaster == 0) {
        sizeID = 1;
    } else {
        sizeID = sizeMaster[repo.getSizeLines() - 1].getIdNumber();
    }
}
void DataBase::setTypeID() {
    if (typeMaster == 0) {
        typeID = 1;
    } else {
    typeID = typeMaster[repo.getTypeLines() - 1].getIdNumber();
    }
}
void DataBase::setPriceID() {
    if (priceMaster == 0) {
        priceID = 1;
    } else {
    priceID = priceMaster[repo.getPriceLines() - 1].getIdNumber();
    }
}
void DataBase::setToppingID() {
    if (toppingMaster == 0) {
        toppingID = 1;
    } else {
    toppingID = toppingMaster[repo.getToppingLines() - 1].getIdNumber();
    }
}

