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
    if(inactiveOrderMaster != 0) {
        delete[] inactiveOrderMaster;
    } else {
        delete inactiveOrderMaster;
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
void DataBase::refreshExtra() {
    if (extraMaster != 0) {
        delete[] extraMaster;
    } else {
        delete extraMaster;
    }
    extraMaster = repo.readExtraFile();
}
void DataBase::refreshLocation() {
    if (locationMaster != 0) {
        delete[] locationMaster;
    } else {
        delete locationMaster;
    }
    locationMaster = repo.readLocationFile();
}
void DataBase::refreshActiveOrder() {
    if (activeOrderMaster != 0) {
        delete[] activeOrderMaster;
    } else {
        delete activeOrderMaster;
    }
    activeOrderMaster = repo.readActiveOrderFile();
}
void DataBase::refreshInactiveOrder() {
    if (priceMaster != 0) {
        delete[] inactiveOrderMaster;
    } else {
        delete inactiveOrderMaster;
    }
    inactiveOrderMaster = repo.readInactiveOrderFile();
}
void DataBase::refreshPizza() {
    if (pizzaMaster != 0) {
        delete[] pizzaMaster;
    } else {
        delete pizzaMaster;
    }
    pizzaMaster = repo.readPizzaFile();
}
void DataBase::refreshSauce() {
    if (sauceMaster != 0) {
        delete[] sauceMaster;
    } else {
        delete sauceMaster;
    }
    sauceMaster = repo.readSauceFile();
}

void DataBase::refreshSize() {
    if (sizeMaster != 0) {
        delete[] sizeMaster;
    } else {
        delete sizeMaster;
    }
    sizeMaster = repo.readSizeFile();
}
void DataBase::refreshType() {
    if (typeMaster != 0) {
        delete[] typeMaster;
    } else {
        delete typeMaster;
    }
    typeMaster = repo.readTypeFile();
}

void DataBase::refreshPrice() {
    if (priceMaster != 0) {
        delete[] priceMaster;
    } else {
        delete priceMaster;
    }
    priceMaster = repo.readPriceFile();
}
void DataBase::refreshTopping() {
    if (toppingMaster != 0) {
        delete[] toppingMaster;
    } else {
        delete toppingMaster;
    }
    toppingMaster = repo.readToppingFile();
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
    if (extraMaster == 0) {
        extraID = 0;
    } else {
        extraID = extraMaster[repo.getExtraLines() - 1].getIdNumber();
    }
}
void DataBase::setLocationID() {
    if (locationMaster == 0) {
        locationID = 0;
    } else {
        locationID = locationMaster[repo.getLocationLines() - 1].getIdNumber();
    }
}
void DataBase::setOrderID() {
    if (activeOrderMaster != 0 && inactiveOrderMaster == 0) {
        orderID = inactiveOrderMaster[repo.getInactiveOrderLines() - 1].getOrderId();
    } else if (activeOrderMaster == 0 && inactiveOrderMaster != 0) {
        orderID = activeOrderMaster[repo.getActiveOrderLines() - 1].getOrderId();
    } else if (activeOrderMaster == 0 && inactiveOrderMaster == 0) {
        orderID = 0;
    } else if(activeOrderMaster[repo.getActiveOrderLines() - 1].getOrderId() > inactiveOrderMaster[repo.getInactiveOrderLines() - 1].getOrderId()) {
        orderID = activeOrderMaster[repo.getActiveOrderLines() - 1].getOrderId();
    } else {
        orderID = inactiveOrderMaster[repo.getInactiveOrderLines() - 1].getOrderId();
    }
}
void DataBase::setPizzaID() {
    if (pizzaMaster == 0) {
        pizzaID = 0;
    } else {
        pizzaID = pizzaMaster[repo.getPizzaLines() - 1].getIdNumber();
    }
}
void DataBase::setSauceID() {
    if (sauceMaster == 0) {
        sauceID = 0;
    } else {
        sauceID = sauceMaster[repo.getSauceLines() - 1].getIdNumber();
    }
}
void DataBase::setSizeID() {
    if (sizeMaster == 0) {
        sizeID = 0;
    } else {
        sizeID = sizeMaster[repo.getSizeLines() - 1].getIdNumber();
    }
}
void DataBase::setTypeID() {
    if (typeMaster == 0) {
        typeID = 0;
    } else {
    typeID = typeMaster[repo.getTypeLines() - 1].getIdNumber();
    }
}
void DataBase::setPriceID() {
    if (priceMaster == 0) {
        priceID = 0;
    } else {
    priceID = priceMaster[repo.getPriceLines() - 1].getIdNumber();
    }
}
void DataBase::setToppingID() {
    if (toppingMaster == 0) {
        toppingID = 0;
    } else {
    toppingID = toppingMaster[repo.getToppingLines() - 1].getIdNumber();
    }
}

