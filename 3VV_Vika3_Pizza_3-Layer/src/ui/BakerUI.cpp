#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::startUp() {
    int c;
    int d;
    int e;
    int f;
    while(c != 0) {
        system("CLS");
        cout <<"Locations: "<<endl;
        displayLocations();
        cout << "Select Location: ";
        cin >> c;
        /// validate input í orderservice
        displayOrders(c);
        do{
            cout << "Select an order: ";
            cin >> d;
        }while(!(d <= repo.getActiveOrderLines()));
        f = findOrderID(d,c);
        displayOrder(f);
        cout <<" set pizza to \"on the make line\"(2), \"done\"(3) or no change(0): ";
        cin >> e;
        dataBase.refreshActiveOrder();
        Order* orderList = dataBase.activeOrderMaster;
        if (e == 2) {
            for(int i = 0; i < repo.getActiveOrderLines(); i++) {
                if(orderList[i].getOrderId() == f) {
                    //setOrderStatus(e);
                }
            }
        }
        else if(e == 3) {
            for(int i = 0; i < repo.getActiveOrderLines(); i++) {
                if(orderList[i].getOrderId() == f) {
                    //setOrderStatus(e);
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
    int counter = 1;
    cout << "Orders already on the make line: " << endl;
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                cout <<"\n" << counter <<")\t|";
                cout << "ID: " <<orderList[i].getOrderId();
                cout << ")\t" << setw(24) << left << orderList[i].getName();
                cout << " | " << setw(5) << left << orderList[i].getComment() << endl;
                counter++;
            }
        }
    }
    cout <<"\n**********************************************************" << endl;
    cout <<"\nOrders ready for the make line: " << endl;
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 1) {
                cout << "\n" << counter <<")\t";
                cout << "ID: " << orderList[i].getOrderId();
                cout << ")\t" << setw(24) << left << orderList[i].getName();
                cout << " | " << setw(5) << left << orderList[i].getComment();
                counter++;
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
            if(toppings[i].getIdNumber() != 0) {

                cout <<toppings[i].getName() << ", ";
            }
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
