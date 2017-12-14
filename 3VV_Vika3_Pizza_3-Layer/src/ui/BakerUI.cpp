#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::startUp() {
    int locationSelection, orderSelection, SelectedOrderId, orderStatus;
    bool valid;
    char userInput;
    system("CLS");
        cout <<"Locations: " <<endl;
        displayLocations();
        do {
            cout << "Select Location: ";
            cin >> locationSelection;
            valid = false;
            validate.isInt(locationSelection);
            try {
                validate.validateLocation(locationSelection, valid);
            } catch(InvalidLocationException) {
                cout << "Invalid location, try again." << endl;
            }
        } while(!valid);
    do {
        system("CLS");
        if(orderService.validateOrdersInLocation(locationSelection)) {
            cout << "Location: " << dataBase.locationMaster[locationSelection - 1].getName() << endl;
            displayOrders(locationSelection);

            do{
                cout << endl << "Select an order: ";
                cin >> orderSelection;
                valid = false;
                validate.isInt(orderSelection);
                try {
                    validate.validateActiveOrderSelection(orderSelection, valid);
                } catch(InvalidActiveOrderException) {
                    cout << "Invalid order selection, try again." << endl;
                }
            } while(!valid);
            SelectedOrderId = findOrderID(orderSelection, locationSelection);
            displayOrder(SelectedOrderId);
            do {
                cout <<"Set pizza status to \"In progress\"(1), \"done\"(2), \"Oh fuck, I dropped it\"(3) or no change(0): ";
                cin >> orderStatus;
                validate.isInt(SelectedOrderId);
            } while(!(0 <= orderStatus && orderStatus <= 3));

            Order* orderList = dataBase.activeOrderMaster;
            if (orderStatus == 1) {
                for(int i = 0; i < repo.getActiveOrderLines(); i++) {
                    if(orderList[i].getOrderId() == SelectedOrderId) {
                        orderList[i].setOrderStatus(2);
                        orderService.saveOrders(orderList);
                    }
                }
            } else if(orderStatus == 2) {
                for(int i = 0; i < repo.getActiveOrderLines(); i++) {
                    if(orderList[i].getOrderId() == SelectedOrderId) {
                        orderList[i].setOrderStatus(3);
                        orderService.saveOrders(orderList);

                    }
                }
            } else if(orderStatus == 3) {
                for(int i = 0; i < repo.getActiveOrderLines(); i++) {
                    if(orderList[i].getOrderId() == SelectedOrderId) {
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
        }
        cin >> userInput;
    } while(userInput == 'y');
}

void BakerUI::displayLocations() {
    //dataBase.refreshLocation();
    Location* locationList = dataBase.locationMaster;
        for(int i = 0; i < dataBase.getLocationID(); i++) {
            cout <<locationList[i].getIdNumber();
            cout << ")\t" << setw(locationList[0].MAX_STRING_LENGTH) << left << locationList[i].getName();
            cout << " | " << locationList[i].getAddress();
            cout << endl;
        }
}

void BakerUI::displayOrders(int locationID) {
    //dataBase.refreshActiveOrder();
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
}

void BakerUI::displayOrder(int orderID) {
    dataBase.refreshActiveOrder();
    Order* orderList = dataBase.activeOrderMaster;
    Pizza* pizzaList;
    Extra* extraList;
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getOrderId() == orderID) {
            pizzaList = orderList[i].getPizzas();
            cout <<"OrderID: " << orderList[i].getOrderId();
            for(int j = 0; j < orderList[0].MAX_PIZZAS_ORDER; j++ ) {
                    //pizzaList[j].getSize().getIdNumber() != 0 checkar hvort að pizzan hafi size
                if(pizzaList[j].getSize().getIdNumber() != 0) {
                    displayPizza(pizzaList[j]);
                }
            }
        }
    }
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if (orderList[i].getOrderId() == orderID) {
            extraList = orderList[i].getExtras();
            cout <<"Extras:" << endl;
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
    Topping* toppings = pizza.getToppings();
    cout << endl;
    cout <<"\n" << pizza.getName();
    cout <<"\t" << "base: " << pizza.getType().getName();
    cout <<"\t" << "size: " << pizza.getSize().getName();
    cout <<"\t" << "sauce: " << pizza.getSauce().getName() << endl;
    cout <<"Toppings: ";
    for(int i = 0; pizza.getToppings()[i].getName() != ""; i++) {
        if(toppings[i].getIdNumber() != 0) {
            cout << toppings[i].getName() << ", ";
        }
    }
    cout <<endl;
}

void BakerUI::displayExtra(Extra extra) {
    cout  << extra.getName() << endl;
}

int BakerUI::findOrderID(int counter, int locationID) {
    dataBase.refreshActiveOrder();
    Order* orderList = dataBase.activeOrderMaster;
    int counter2 = 1;
       for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                if(counter2 == counter) {
                    return orderList[i].getOrderId();
                }
                counter2++;
            }
        }
    }

    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 1) {
                if(counter2 == counter) {
                    return orderList[i].getOrderId();
                }
                counter2++;
            }
        }
    }
    return 0;
}
