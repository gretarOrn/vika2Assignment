#include "DeliveryUI.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}
void DeliveryUI::startUp() {
    int c,d;
    char answer;
    Order* orderList = dataBase.activeOrderMaster;
    while(c != 0) {
        system("CLS");
        cout <<"Locations: "<<endl;
        displayLocations();
        cout << "Select Location: ";
        cin >> c;
        /// validate input � orderservice
        displayOrders(d);
        cout << "Select OrderID: ";
        cin >> d;
        for(int i = 0; i < dataBase.getOrderID(); i++) {
            if(orderList[i].getLocationId() == c) {
                if(orderList[i].getOrderId() == d) {
                    if(orderList[i].getOrderStatus() == 3){
                        cout <<"Set order to \"in transit\"?(y/n): ";
                        cin >>answer;
                        if(answer == 'y') {
//                            OrderService.setOrderStatus(4);
                        }
                    }
                    else if(orderList[i].getOrderStatus() == 4) {
                        cout <<"Set order to \"delivered\"?(y/n): ";
                        cin >>answer;
                        if(answer == 'y') {
//                            OrderService.setOrderStatus(5);
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
    cout << "Orders ready for delivery: " << endl;
    for(int i = 0; i < dataBase.getOrderID(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 3) {
                cout << "\n" << orderList[i].getOrderId();
                cout << ")\t" << setw(24) << left << orderList[i].getName();
                cout << " | " << setw(5) << left << orderList[i].getAddress();
            }
        }
    }
    cout <<"\n**********************************************************" << endl;
    cout <<"\nOrders in transit: " << endl;
    for(int i = 0; i < dataBase.getOrderID(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                cout << "\n" << orderList[i].getOrderId();
                cout << ")\t" << setw(24) << left << orderList[i].getName();
                cout << " | " << setw(5) << left << orderList[i].getAddress();
            }
        }
    }
}