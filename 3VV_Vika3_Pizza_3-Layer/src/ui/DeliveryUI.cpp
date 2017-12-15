#include "DeliveryUI.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}

void DeliveryUI::startUp() {
    int locationSelection, orderSelection, selectedOrderId, orderStatus, orderCount, allOrderLines;
    bool valid;
    bool paymentError = false;
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
                validate.validateOrdersInLocationDelivery(locationSelection, valid);
            } catch(InvalidLocationException) {
                cout << "Invalid location, try again." << endl;
            } catch(InvalidActiveOrderException) {
                cout << "No orders in location, try again later." << endl;
            }
        } while(!valid);
        do {
            system("CLS");
                if(paymentError) {
                    cout << "Cannot deliver order without payment. pay first" << endl << endl;
                    paymentError = false;
                }
                cout << "Location: " << dataBase.locationMaster[locationSelection - 1].getName() << " | Delivery" << endl;
                orderCount = displayOrders(locationSelection);
                allOrderLines = repo.getActiveOrderLines();
                do {
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
                            if(orderList[i].getPaymentStatus()) {
                                orderList[i].setOrderStatus(5);
                                orderService.moveOrderToInactiveFile(i);
                            } else {
                                paymentError = true;
                                break;
                            }
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
            if(orderList[i].getOrderStatus() == 3) {
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
    cout << endl << "****************************************************************************************" << endl;
    cout << "Orders in progress: " << endl;
    for(int i = 0; i < lines; i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                cout << counter << ")\t";
                cout << "Order ID: " << setw(5) << right << orderList[i].getOrderId();
                cout << " | ";
                if(orderList[i].isDelivered()) {
                    cout << "Address: ";
                } else {
                    cout << "Pickup:  ";
                }
                cout << setw(dataBase.locationMaster[0].MAX_ADDRESS_LENGTH) << left << orderList[i].getAddress();
                if(orderList[i].getPaymentStatus()){
                    cout << " | Payment status: Payed" << endl;
                } else {
                    cout << " | Payment status: Pay on delivery" << endl;
                }
                counter++;
            }
        }
    }
    cout << endl << "****************************************************************************************" << endl;
    cout << "Orders awaiting processing: " << endl;
    for(int i = 0; i < lines; i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                cout << counter << ")\t";
                cout << "Order ID: " << setw(5) << right << orderList[i].getOrderId();
                cout << " | ";
                if(orderList[i].isDelivered()) {
                    cout << "Address: ";
                } else {
                    cout << "Pickup:  ";
                }
                cout << setw(dataBase.locationMaster[0].MAX_ADDRESS_LENGTH) << left << orderList[i].getAddress();
                if(orderList[i].getPaymentStatus()){
                    cout << " | Payment status: Payed" << endl;
                } else {
                    cout << " | Payment status: Pay on delivery" << endl;
                }
                counter++;
            }
        }
    }
    cout << endl << "****************************************************************************************" << endl;
    return counter;
}

int DeliveryUI::findOrderID(int orderSelection, int locationID) {
    Order* orderList = dataBase.activeOrderMaster;
    int lines = repo.getActiveOrderLines();
    int counter = 1;
       for(int i = 0; i < lines; i++) {
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
    for(int i = 0; i < lines; i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 3) {
                if(orderList[i].isDelivered()) {
                    if(counter == orderSelection) {
                        return orderList[i].getOrderId();
                    }
                    counter++;
                }
            }
        }
    }
    for(int i = 0; i < lines; i++) {
        if(orderList[i].getLocationId() == locationID) {
            if(orderList[i].getOrderStatus() == 2) {
                if(counter == orderSelection) {
                    return orderList[i].getOrderId();
                }
                counter++;
            }
        }
    }
    for(int i = 0; i < lines; i++) {
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
