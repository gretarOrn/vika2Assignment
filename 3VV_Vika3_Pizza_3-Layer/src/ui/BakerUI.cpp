#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::startUp() {
    int locationSelection, orderSelection, SelectedOrderId, orderStatus;
    bool valid;
    OrderService orderService;
    system("CLS");
    while(locationSelection != 0) {
        cout <<"Locations: "<<endl;
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
    system("CLS");
    if (orderService.validateOrdersInLocation(locationSelection)) {
        cout << "Location: " << dataBase.locationMaster[locationSelection - 1].getName() << endl;
        displayOrders(locationSelection);
        do{
            cout << "Select an order: ";
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
        cout <<"Set pizza status to \"In progress\"(2), \"done\"(3) or no change(0): ";
        cin >> orderStatus;
        dataBase.refreshActiveOrder();
        Order* orderList = dataBase.activeOrderMaster;
        if (orderStatus == 2) {
            for(int i = 0; i < repo.getActiveOrderLines(); i++) {
                if(orderList[i].getOrderId() == SelectedOrderId) {
                    orderList[i].setOrderStatus(orderStatus);
                    orderService.saveOrders(orderList);
                    dataBase.refreshActiveOrder();
                }
            }
        }
        else if(orderStatus == 3) {
            for(int i = 0; i < repo.getActiveOrderLines(); i++) {
                if(orderList[i].getOrderId() == SelectedOrderId) {
                    orderList[i].setOrderStatus(orderStatus);
                    orderService.saveOrders(orderList);
                    dataBase.refreshActiveOrder();
                }
            }
        }
    }
    else  {
        cout << "No orders in that location: " << endl;
        cout << "Select another location: " << endl;
        }
    }
}

void BakerUI::displayLocations() {
    dataBase.refreshLocation();
    Location* locationList = dataBase.locationMaster;
        for(int i = 0; i < dataBase.getLocationID(); i++) {
            cout <<locationList[i].getIdNumber();
            cout << ")\t" << setw(24) << left << locationList[i].getName();
            cout << " | " << setw(5) << left << locationList[i].getAddress();
            if(locationList[i].getActiveState()) {
                cout << "\t|Active";
            } else {
                cout << "\t|Inactive";
            }
            cout << endl;
        }
}
void BakerUI::displayOrders(int locationID) {
    dataBase.refreshActiveOrder();
    Order* orderList = dataBase.activeOrderMaster;
    int counter = 1;
    cout << "******************************************************************************" << endl;
    cout << "Orders already in progress: " << endl;
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                cout << counter << ")\t";
                cout << "Order ID: " << orderList[i].getOrderId();
                cout << "\t" << setw(24) << left << orderList[i].getAddress();
                cout << " | " << setw(5) << left << orderList[i].getComment() << endl;
                counter++;
            }
        }
    }

    cout << endl << "******************************************************************************" << endl;
    cout << "Orders ready for processing: ";
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 1) {


                cout << "\n" << counter <<")\t|";
                cout << "ID: " << orderList[i].getOrderId();
                cout << ")\t" << setw(24) << left << orderList[i].getAddress();

                cout << " | " << setw(5) << left << orderList[i].getComment() << endl;
                counter++;
            }
        }
    }
}
void BakerUI::displayPizza(Pizza pizza) {
    Topping* toppings = pizza.getToppings();
    cout << endl;
    cout <<"\n" << pizza.getName();
    cout <<"\t" << "base: " << pizza.getType().getName();
    cout <<"\t" << "sauce: " << pizza.getSize().getName();
    cout <<"\t" << "sauce: " << pizza.getSauce().getName() << endl;
    cout <<"Toppings: ";
    for(int i = 0; pizza.getToppings()[i].getName() != ""; i++) {
            if(toppings[i].getIdNumber() != 0) {

                cout <<toppings[i].getName() << ", ";
            }
    }
    cout <<endl;

}
void BakerUI::displayExtra(Extra extra) {
    cout  << extra.getName() << "\n";
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
