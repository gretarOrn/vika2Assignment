#include "DeliveryUI.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}

void DeliveryUI::startUp() {
    int locationSelection, orderSelection, selectedOrderId, orderStatus, orderCount, allOrderLines;
    bool valid;
    while(true) {
        system("CLS");
        cout << "Delivery:" << endl;
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
                cout << "Location: " << dataBase.locationMaster[locationSelection - 1].getName() << " | Delivery" << endl;
                orderCount = displayOrders(locationSelection);
                allOrderLines = repo.getActiveOrderLines();
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
                }while(!valid);
                selectedOrderId = findOrderID(orderSelection, locationSelection);
                do {
                    if(orderSelection == 0) {
                        break;
                    }
                    cout << "Set order status to: " << endl;
                    cout << "1)  Payed" << endl;
                    cout << "2)  Delivered" << endl;
                    cout << "3)  Oh fuck, I dropped it" << endl;
                    cout << "0)  Go back" << endl;
                    cin >> orderStatus;
                    validate.isInt(selectedOrderId);
                } while(!(0 <= orderStatus && orderStatus <= 3));

                Order* orderList = dataBase.activeOrderMaster;
                allOrderLines = repo.getActiveOrderLines();
                if (orderStatus == 1) {
                    for(int i = 0; i < allOrderLines; i++) {
                        if(orderList[i].getOrderId() == selectedOrderId) {
                            orderList[i].setOrderStatus(3);
                            orderList[i].setPaymentStatus(true);
                            orderService.saveOrders(orderList);
                        }
                    }
                } else if(orderStatus == 2) {
                    for(int i = 0; i < allOrderLines; i++) {
                        if(orderList[i].getOrderId() == selectedOrderId) {
                            orderList[i].setOrderStatus(5);
                            orderService.moveOrderToInactiveFile(i);
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

void DeliveryUI::displayLocations() {
    Location* locationList = dataBase.locationMaster;
        for(int i = 0; i < dataBase.getLocationID(); i++) {
            cout <<locationList[i].getIdNumber();
            cout << ")\t" << setw(locationList[0].MAX_STRING_LENGTH) << left << locationList[i].getName();
            cout << " | " << locationList[i].getAddress();
            cout << endl;
        }
}

int DeliveryUI::displayOrders(int locationID) {
    Order* orderList = dataBase.activeOrderMaster;
    int counter = 1;
    int lines = repo.getActiveOrderLines();
    cout << endl << "****************************************************************************************" << endl;
    cout << "Orders ready for pickup: " << endl;
    for(int i = 0; i < lines; i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 3 || orderList[i].getOrderStatus() == 4) {
               if(!orderList[i].isDelivered()) {
                    cout << counter << ")\t";
                    cout << "Order ID: " << setw(5) << right << orderList[i].getOrderId();
                    cout << " | Pickup:  " << setw(dataBase.locationMaster[0].MAX_ADDRESS_LENGTH) << left << orderList[i].getAddress();
                    if(orderList[i].getPaymentStatus()){
                        cout << " | Payment status: Payed" << endl;
                    } else {
                        cout << " | Payment status: Pay on delivery" << endl;
                    }
                    counter++;
               }
            }
        }
    }
    cout << endl << "****************************************************************************************" << endl;
    cout << "Orders ready for delivery: " << endl;
    for(int i = 0; i < lines; i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 3) {
                if(orderList[i].isDelivered()) {
                    cout << counter << ")\t";
                    cout << "Order ID: " << setw(5) << right << orderList[i].getOrderId();
                    cout << " | Address: " << setw(dataBase.locationMaster[0].MAX_ADDRESS_LENGTH) << left << orderList[i].getAddress();
                    if(orderList[i].getPaymentStatus()){
                        cout << " | Payment status: Payed" << endl;
                    } else {
                        cout << " | Payment status: Pay on delivery" << endl;
                    }
                    counter++;
                }
            }
        }
    }
    return counter;
}

int DeliveryUI::findOrderID(int orderSelection, int locationID) {
    Order* orderList = dataBase.activeOrderMaster;
    int counter = 1;
       for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 3) {
                if(!orderList[i].isDelivered()) {
                    if(counter == orderSelection) {
                        return orderList[i].getOrderId();
                    }
                counter++;
                }
            }
        }
    }
    for(int i = 0; i < repo.getActiveOrderLines(); i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 4) {
                if(orderList[i].isDelivered()) {
                    if(counter == orderSelection) {
                        return orderList[i].getOrderId();
                    }
                    counter++;
                }
            }
        }
    }
    return 0;
}
