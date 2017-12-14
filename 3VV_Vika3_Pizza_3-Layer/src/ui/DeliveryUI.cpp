#include "DeliveryUI.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}
void DeliveryUI::startUp() {
    int c,d;
    int orderID;
    char answer;
    Order* orderList = dataBase.activeOrderMaster;
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
        orderID = findOrderID(d,c);
        for(int i = 0; i < dataBase.getOrderID(); i++) {
            if(orderList[i].getLocationId() == c) {
                if(orderList[i].getOrderId() == orderID) {
                    if(orderList[i].getOrderStatus() == 3){
                        cout <<"Set order to \"in transit\"?(y/n): ";
                        cin >>answer;
                        if(answer == 'y') {
                            orderList[i].setOrderStatus(4);
                            orderService.saveOrders(orderList);
                            dataBase.refreshActiveOrder();
                        }
                    }
                    else if(orderList[i].getOrderStatus() == 4) {
                        cout <<"Set order to \"delivered\"?(y/n): ";
                        cin >>answer;
                        if(answer == 'y') {
                            orderList[i].setOrderStatus(5);
                            orderService.saveOrders(orderList);
                            dataBase.refreshActiveOrder();
                        }
                    }
                }
            }
        }


    }
}
void DeliveryUI::displayLocations() {
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
void DeliveryUI::displayOrders(int locationID) {
    dataBase.refreshActiveOrder();
    Order* orderList = dataBase.activeOrderMaster;
    int counter = 1;
    cout << "Orders ready for delivery: " << endl;
    for(int i = 0; i < dataBase.getOrderID(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 3) {
                cout <<counter <<")\t|";
                cout << "ID:" << orderList[i].getOrderId();
                cout << ")\t" << setw(24) << left << orderList[i].getName();
                cout << " | " << setw(5) << left << orderList[i].getAddress() << endl;
                counter++;
            }
        }
    }
    cout <<"\n**********************************************************" << endl;
    cout <<"\nOrders in transit: " << endl;
    for(int i = 0; i < dataBase.getOrderID(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 4) {
                cout << counter <<")\t|";
                cout << "ID:" << orderList[i].getOrderId();
                cout << ")\t" << setw(24) << left << orderList[i].getName();
                cout << " | " << setw(5) << left << orderList[i].getAddress() << endl;
                counter++;
            }
        }
    }
}
int DeliveryUI::findOrderID(int counter, int locationID) {
    dataBase.refreshActiveOrder();
    Order* orderList = dataBase.activeOrderMaster;
    int counter2 = 1;
       for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 3) {
                if(counter2 == counter) {
                    return orderList[i].getOrderId();
                }
                counter2++;
            }
        }
    }

    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 4) {
                if(counter2 == counter) {
                    return orderList[i].getOrderId();
                }
                counter2++;
            }
        }
    }
    return 0;
}
