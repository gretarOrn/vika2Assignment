#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::startUp() {
    int c;
    int d;
    while(c != 0) {
        system("CLS");
        cout <<"Locations: "<<endl;
        displayLocations();
        cout << "Select Location: ";
        cin >> c;
        /// validate input í orderservice
        displayOrders(c);
        cout << "Select OrderID: ";
        cin >> c;
        displayOrder(c);
        cout <<" set pizza to \"on the make line\"(2), \"done\"(3) or no change(0): ";
        cin >> d;
        dataBase.refreshActiveOrder();
        Order* orderList = dataBase.activeOrderMaster;
        if (d == 2) {
            for(int i = 0; i < dataBase.getOrderID(); i++) {
                if(orderList[i].getOrderId() == c) {
                    //setOrderStatus(d);
                }
            }
        }
        else if(d == 3) {
            for(int i = 0; i < dataBase.getOrderID(); i++) {
                if(orderList[i].getOrderId() == c) {
                    //setOrderStatus(d);
                }
            }
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
    cout << "Orders already on the make line: " << endl;
    for(int i = 0; i < dataBase.getOrderID(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                cout << "\n" << orderList[i].getOrderId();
                cout << ")\t" << setw(24) << left << orderList[i].getName();
                cout << " | " << setw(5) << left << orderList[i].getComment();
            }
        }
    }
    cout <<"\n**********************************************************" << endl;
    cout <<"\nOrders ready for the make line: " << endl;
    for(int i = 0; i < dataBase.getOrderID(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 1) {
                cout << "\n" << orderList[i].getOrderId();
                cout << ")\t" << setw(24) << left << orderList[i].getName();
                cout << " | " << setw(5) << left << orderList[i].getComment();
            }
        }
    }
}
void BakerUI::displayPizza(Pizza pizza) {
    Topping* toppings = pizza.getToppings();
    cout << endl;
    cout <<"\n" << pizza.getName();
    cout <<"\t" << pizza.getType().getName();
    cout <<"\t" << pizza.getSize().getName();
    cout <<"\t" << pizza.getSauce().getName() << endl;
    cout <<"Toppings: ";
    for(int i = 0; i < pizza.MAX_TOPPINGS_PIZZA; i++) {
        cout <<toppings[i].getName() << ", ";
    }
    cout <<endl;

}
void BakerUI::displayExtra(Extra extra) {
    cout << endl;
    cout <<"\n" << extra.getName() << endl;
}
void BakerUI::displayOrder(int orderID) {
    dataBase.refreshActiveOrder();
    Order* orderList = dataBase.activeOrderMaster;
    Pizza* pizzaList;
    Extra* extraList;
    for(int i = 0; i < dataBase.getOrderID(); i++) {
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
    for(int i = 0; i < dataBase.getOrderID(); i++) {
        extraList = orderList[i].getExtras();
        cout <<"Extras:" << endl;
        for(int j = 0; j < orderList[0].MAX_EXTRAS_ORDER; j++) {
            if(extraList[j].getName() != "") {
                displayExtra(extraList[j]);
            }
        }
    }
}
