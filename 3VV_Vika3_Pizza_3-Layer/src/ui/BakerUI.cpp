#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::startUp() {
    int locationSelection, orderSelection, selectedOrderId, orderStatus, orderCount, allOrderLines;

    bool valid;
    while(true) {
        system("CLS");
        cout << "Baking:" << endl;
        cout << "Locations: " << endl;
        displayLocations();
        do {
            cout << "Select Location, press 0 to go back: ";
            cin >> locationSelection;
            valid = false;
            validate.isInt(locationSelection);
            if(locationSelection == 0) {
                return;
            } try {
                validate.validateLocation(locationSelection, valid);
            } catch(InvalidLocationException) {
                cout << "Invalid location, try again." << endl;
            }
        } while(!valid);
        do {
            system("CLS");
            if(orderService.validateOrdersInLocation(locationSelection)) {
                cout << "Location: " << dataBase.locationMaster[locationSelection - 1].getName() << " | Baking" << endl;
                orderCount = displayOrders(locationSelection);
                do{
                    cout << endl << "Select an order, press 0 to go back: ";
                    cin >> orderSelection;
                    valid = false;
                    validate.isInt(orderSelection);
                    if(orderSelection == 0) {
                        break;
                    } try {
                        validate.validateActiveOrderSelection(orderSelection, orderCount, valid);
                    } catch(InvalidActiveOrderException) {
                        cout << "Invalid order selection, try again." << endl;
                    }
                } while(!valid);
                selectedOrderId = findOrderID(orderSelection, locationSelection);
                displayOrder(selectedOrderId);
                do {
                    if(orderSelection == 0) {
                        break;
                    }
                    cout << "Set order status to: " << endl;
                    cout << "1)  In progress" << endl;
                    cout << "2)  Done" << endl;
                    cout << "3)  Oh fuck, I dropped it" << endl;
                    cout << "0)  Go back" << endl;
                    cin >> orderStatus;
                    validate.isInt(selectedOrderId);
                } while(!(0 <= orderStatus && orderStatus <= 3));

                Order* orderList = dataBase.activeOrderMaster;
                if (orderStatus == 1) {
                    for(int i = 0; i < allOrderLines; i++) {
                        if(orderList[i].getOrderId() == selectedOrderId) {
                            orderList[i].setOrderStatus(2);
                            orderService.saveOrders(orderList);
                        }
                    }
                } else if(orderStatus == 2) {
                    for(int i = 0; i < allOrderLines; i++) {
                        if(orderList[i].getOrderId() == selectedOrderId) {
                            orderList[i].setOrderStatus(3);
                            orderService.saveOrders(orderList);
                        }
                    }
                } else if(orderStatus == 3) {
                    for(int i = 0; i < allOrderLines; i++) {
                        if(orderList[i].getOrderId() == selectedOrderId) {
                            orderList[i].setOrderStatus(6);
                            orderService.copyOrderToInactiveFile(orderList[i]);
                            orderList[i].setOrderStatus(1);
                            orderService.saveOrders(orderList);
                        }
                    }
                }
            } else {
                cout << "No orders in that location: " << endl;
                cout << "Select another location: " << endl;
                orderSelection = 0;
            }
        } while(orderSelection != 0);
    }
}

void BakerUI::displayLocations() {
    Location* locationList = dataBase.locationMaster;
        for(int i = 0; i < dataBase.getLocationID(); i++) {
            cout <<locationList[i].getIdNumber();
            cout << ")\t" << setw(locationList[0].MAX_STRING_LENGTH) << left << locationList[i].getName();
            cout << " | " << locationList[i].getAddress();
            cout << endl;
        }
}

int BakerUI::displayOrders(int locationID) {
    Order* orderList = dataBase.activeOrderMaster;
    int counter = 1;
    cout << endl << "****************************************************************************************" << endl;
    cout << "Orders already in progress: " << endl;
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                cout << counter << ")\t";
                cout << "Order ID: " << setw(5) << right << orderList[i].getOrderId() << " | ";
                if(orderList[i].isDelivered()) {
                    cout << "Address: ";
                } else {
                    cout << "Pickup:  ";
                }
                cout << setw(dataBase.locationMaster[0].MAX_ADDRESS_LENGTH) << left << orderList[i].getAddress();
                cout << " | Comment: " << orderList[i].getComment() << endl;
                counter++;
            }
        }
    }
    cout << endl << "****************************************************************************************" << endl;
    cout << "Orders ready for processing: " << endl;
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 1) {
                cout << counter << ")\t";
                cout << "Order ID: " << setw(5) << right << orderList[i].getOrderId() << " | ";
                if(orderList[i].isDelivered()) {
                    cout << "Address: ";
                } else {
                    cout << "Pickup:  ";
                }
                cout << setw(dataBase.locationMaster[0].MAX_ADDRESS_LENGTH) << left << orderList[i].getAddress();
                cout << " | Comment: " << orderList[i].getComment() << endl;
                counter++;
            }
        }
    }
    return counter;
}

void BakerUI::displayOrder(int orderID) {
    Order* orderList = dataBase.activeOrderMaster;
    Pizza* pizzaList;
    Extra* extraList;
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getOrderId() == orderID) {
            pizzaList = orderList[i].getPizzas();
            cout << "OrderID: " << orderList[i].getOrderId() << endl;
            cout << "Pizzas: " << endl;
            for(int j = 0; j < orderList[0].MAX_PIZZAS_ORDER; j++ ) {
                // pizzaList[j].getSize().getIdNumber() != 0 checkar hvort að pizzan hafi size
                if(pizzaList[j].getSize().getIdNumber() != 0) {
                    displayPizza(pizzaList[j]);
                }
            }
        }
    }
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getOrderId() == orderID) {
            extraList = orderList[i].getExtras();
            cout << "Extras: " << endl;
            for(int j = 0; j < orderList[0].MAX_EXTRAS_ORDER; j++) {
                if(extraList[j].getName() != "") {
                    displayExtra(extraList[j]);
                }
            }
            cout << endl;
        }
    }
}

void BakerUI::displayPizza(Pizza pizza) {
    if(pizza.getName() != "") {
        cout << "  " << pizza.getName() << endl;
    } else {
        cout << "  Custom pizza" << endl;
    }
    cout << "    " <<  setw(9) << pizza.getSize().getName()
         << " | " << pizza.getType().getName() + " base"
         << " | " << pizza.getSauce().getName() + " sauce" << endl;
    cout << "    " << "Toppings: ";
    for(int j = 0; j < pizza.MAX_TOPPINGS_PIZZA; j++) {
        if(pizza.getToppings()[j].getIdNumber() != 0) {
            cout << pizza.getToppings()[j].getName() << ", ";
        }
    }
    cout << endl;
}

void BakerUI::displayExtra(Extra extra) {
    cout << "  " << extra.getName() << endl;
}

int BakerUI::findOrderID(int orderSelection, int locationID) {
    Order* orderList = dataBase.activeOrderMaster;
    int counter = 1;
       for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                if(counter == orderSelection) {
                    return orderList[i].getOrderId();
                }
                counter++;
            }
        }
    }
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 1) {
                if(counter == orderSelection) {
                    return orderList[i].getOrderId();
                }
                counter++;
            }
        }
    }
    return 0;
}
