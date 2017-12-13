#include "SalesUI.h"

SalesUI::SalesUI()
{
    //ctor
}

void SalesUI::startUp() {
    system("CLS");
    int locationId;
    bool valid = true;
    do {
        displayLocationList();
        cout << "Select location: ";
        cin >> locationId;
        ///valid = adminSer.validateLocationSelection(locationId);
    } while(!valid);
    defaultLocationId = locationId;
    system("CLS");
    char c;
    while (c != 'q') {
        //system("CLS");
        cout << "Sales:" << endl;
        cout << "1)\t" << "Create an order" << endl;
        cout << "2)\t" << "Edit an order" << endl;
        cout << "3)\t" << "..............." << endl;
        cout << "q)\t" << "Go back" << endl;

        cin >> c;
        if(c == '1') {
            createOrder();
        } else if(c == '2') {
            Order* orderList = dataBase.activeOrderMaster;
            int index;
            cout << "Lines: " << orderSer.repo.getActiveOrderLines() << endl;
            /*for(int i = 0; i < orderSer.repo.getActiveOrderLines(); i++) {
                displayOrder(orderList[i]);
                cout << endl;
            }*/
            cout << "Select order to move to inactive: ";
            cin >> index;
            orderSer.moveOrderToInactiveFile(index);

            cout << "Lines: " << orderSer.repo.getActiveOrderLines() << endl;
        } else if(c == '3') {
            Order* inactiveOrderList = dataBase.inactiveOrderMaster;
            cout << orderSer.repo.getInactiveOrderLines() << endl;
            /*for(int i = 0; i < orderSer.repo.getInactiveOrderLines(); i++) {
                displayOrder(inactiveOrderList[i]);
                cout << endl;
            }*/
        } else if(c != 'q') {

        }
    }
    system("CLS");
}

void SalesUI::createOrder() {
    Order order;
    char c;
    while (c != 'q') {
        cout << "Order:" << endl;
        cout << "1)\t" << "Add pizza from menu" << endl;
        cout << "2)\t" << "Create custom pizza" << endl;
        cout << "3)\t" << "Add an Extra" << endl;
        cout << "4)\t" << "Complete order" << endl;
        cout << "q)\t" << "Cancel order" << endl;

        cin >> c;
        if(c == '1') {
            addPizzaFromMenu(order);
        } else if(c == '2') {
            createCustomPizza(order);
        } else if(c == '3') {
            addExtraToOrder(order);
        } else if(c == '4') {
            addInfo(order);
            break;
        } else if(c != 'q') {

        }
        system("CLS");
    }

}

void SalesUI::addPizzaFromMenu(Order& order) {
    system("CLS");
    char c;
    int input;
    bool valid = true;
    Pizza* pizzaMenu = dataBase.pizzaMaster;
    do{
        system("CLS");
        cout << "Pizzas in current order: " << endl;
        for(int i = 0; i < order.MAX_PIZZAS_ORDER; i++) {
            if(order.getPizzas()[i].getName() != "") {
                cout << (i + 1) << ")  " << order.getPizzas()[i].getName() << endl;
            }
        }
        cout << "----------------------------------------------------------------" << endl << endl;
        displayPizzaMenu();
        do {

            cout << "Select Pizza: ";
            cin >> input;
            try {
                adminSer.validatePizzaSelection(input,valid);
            }
            catch(InvalidPizzaException) {
                cout <<"Invalid selection." << endl;
            }

        } while(!valid);
        orderSer.addPizzaToOrder(order, pizzaMenu[input - 1]);

        cout << endl << "Add more pizzas from menu? (y/n) ";
        cin >> c;
    } while(c == 'y');
    system("CLS");
    cout << "Pizzas in current order: " << endl;
    for(int i = 0; i < order.MAX_PIZZAS_ORDER; i++) {
        if(order.getPizzas()[i].getName() != "") {
            cout << (i + 1) << ")  " << order.getPizzas()[i].getName() << endl;
        }
    }
}

void SalesUI::createCustomPizza(Order& order) {
    system("CLS");

    cout << "Create a pizza" << endl;
    int i = 0;
    char c;
    int input;
    do {
        system("CLS");
        cout << "Pizzas in current order: " << endl;
        for(int k = 0; k < order.MAX_PIZZAS_ORDER; k++) {
                if(order.getPizzas()[k].getName() != "") {
                    cout << (k + 1) << ")  " << order.getPizzas()[k].getName() << endl;
                    i++;
                } else if(order.getPizzas()[k].getSauce().getIdNumber() != 0) {
                    cout << (k + 1) << ")  Custom pizza" << endl;
                    i++;
                }
        }
        cout << "----------------------------------------------------------------" << endl << endl;

        displaySizeList();
        cout << "Select size: ";
        cin >> input;
        order.getPizzas()[i].setSize(pizzaSer.addSize(input));
        cout << endl;

        displayTypeList();
        cout << "Select type: ";
        cin >> input;
        order.getPizzas()[i].setType(pizzaSer.addType(input));
        cout << endl;

        displaySauceList();
        cout << "Select sauce: " << endl;
        cin >> input;
        order.getPizzas()[i].setSauce(pizzaSer.addSauce(input));
        cout << endl;

        displayToppingList();
        cout << "Select toppings (type 0 to stop)" << endl;
        int counter = 0;
        int arr[dataBase.pizzaMaster[0].MAX_TOPPINGS_PIZZA];
        for (int j = 0; j < dataBase.pizzaMaster[0].MAX_TOPPINGS_PIZZA; j++) {
            cin >> arr[j];
            counter ++;
            if (arr[j] == 0) break;
            //pizzaSer.addPizzaToOrder(order.getPizzas()[i], dataBase.toppingMaster[arr[j]]);
        }
        order.getPizzas()[i].addToppings(pizzaSer.addTopping(arr, order.getPizzas()[i]));
        cout << endl;

        printPizza(order.getPizzas()[i], counter);
        i++;

        cout << "Add another pizza to order? (y/n) " << endl;
        cin >> c;
    } while (c == 'y');
    system("CLS");
    cout << "Pizzas in current order: " << endl;
    for(int k = 0; k < order.MAX_PIZZAS_ORDER; k++) {
        if(order.getPizzas()[k].getName() != "") {
            cout << (k + 1) << ")  " << order.getPizzas()[k].getName() << endl;
        } else if(order.getPizzas()[k].getSauce().getIdNumber() != 0) {
            cout << (k + 1) << ")  Custom pizza" << endl;
        }
    }
}

void SalesUI::addExtraToOrder(Order& order) {
    char c;
    int input;
    for (int i = 0; i < order.MAX_EXTRAS_ORDER; i++) {
        printExtra(order);
        cout << "----------------------------------------------------------------" << endl << endl;
        displayExtraList();
        cout << "Select extra: ";
        cin >> input;
        order.getExtras()[i].addExtra(extraSer.addExtra(input));
        cout << endl;
        cout << "Add another extra to order? (y/n) " << endl;
        cin >> c;
        if (c != 'y') {
            break;
        }
    }
}

void SalesUI::addInfo(Order& order) {
    char userInput;
    int userSelection;
    bool delivery;
    bool payed;
    bool valid;
    string address;
    string comment;
    while(true) {
        cout << "Pickup or delivery? (p/d) ";
        cin >> userInput;
        if(userInput == 'p') {
            delivery = false;
            break;
        } else if(userInput == 'd') {
            delivery = true;
            break;
        } else {
            system("CLS");
            cout << "Try again." << endl;
        }
    }
    valid = false;
    if(delivery) {
        do {
            cout << "Enter delivery address: ";
            cin >> ws;
            getline(cin, address);
            try{
                adminSer.validateName(address, valid);
            } catch(InvalidNameException) {
                cout << "Invalid address." << endl;
            }
        } while(!valid);
        userSelection = defaultLocationId;
    } else {
        valid = false;
        do {
            system("CLS");
            displayLocationList();
            cout << "Select pickup location: ";
            cin >> userSelection;
            try{
                adminSer.validateLocation(userSelection, valid);
            }
            catch(InvalidLocationException) {
                cout <<"Invalid location." << endl;
            }
        } while(!valid);

            cout << "Enter customer name / phone number: ";
            cin >> ws;
            getline(cin, address);
    }
    cout << "Add comment? (y/n) ";
    cin >> userInput;
    if(userInput == 'y') {
        cout << "Comment: ";
        cin >> ws;
        getline(cin, comment);
    }
    while(true) {
        cout << "Has order been payed? (y/n) ";
        cin >> userInput;
        if(userInput == 'y') {
            payed = true;
            break;
        } else if(userInput == 'n') {
            payed = false;
            break;
        } else {
            system("CLS");
            cout << "Try again." << endl;
        }
    }
    orderSer.addInfoToOrder(order, delivery, userSelection, address, comment, payed);
    displayOrder(order);
    cout << "confirm order? (y/n) ";
    cin >> userInput;
    if(userInput == 'y') {
        cout << "Order saved" <<endl;
        orderSer.saveOrder(order);
    } else {
        cout << "Order canceled" << endl;
    }
}

void SalesUI::printPizza(Pizza pizza, int counter) {
    if(pizza.getName() != ""){
        cout << "Name: " << pizza.getName() << endl;
    } else {
        cout << "Name: Custom pizza" << endl;
    }
    cout << "Size: " << pizza.getSize().getName() << endl;
    cout << "Sauce: " << pizza.getSauce().getName() << endl;
    cout << "Type: " << pizza.getType().getName() << endl;
    cout << "Toppings: ";
    for (int i = 0; i < (counter - 1); i++) {
        cout << pizza.getToppings()[i].getName() << ", ";
    }
    cout << endl;
    cout << "Total Price of Pizza: " << pizzaSer.getPrice(pizza) << endl;
    cout << endl;
}

void SalesUI::printExtra(Order& order) {
    system("CLS");
    cout << "Extras in current order: " << endl;
    for(int i = 0; i < order.MAX_EXTRAS_ORDER; i++) {
        if(order.getExtras()[i].getName() != "") {
            cout << (i + 1) << ")  " << order.getExtras()[i].getName() << endl;
        }
    }
}

///******************************************************************************************

void SalesUI::displayOrder(Order& order) {
    Location* locList = dataBase.locationMaster;
    cout << "Order ID: " << order.getOrderId() << endl;
    if(order.getName() != "") {
        cout << order.getName() << endl;
    }
    cout << "Pizzas in current order: " << endl;
    for(int i = 0; i < order.MAX_PIZZAS_ORDER; i++) {
        if(order.getPizzas()[i].getName() != "") {
            cout << (i + 1) << ")  " << order.getPizzas()[i].getName() << endl;
        } else if(order.getPizzas()[i].getSauce().getIdNumber() != 0) {
            cout << (i + 1) << ")  Custom pizza" << endl;
        }
    }
    cout << "Extras in current order: " << endl;
    for(int i = 0; i < order.MAX_EXTRAS_ORDER; i++) {
        if(order.getExtras()[i].getName() != "") {
            cout << (i + 1) << ")  " << order.getExtras()[i].getName() << endl;
        }
    }
    if(order.isDelivered()) {
        cout << "Deliver to: " << order.getAddress() << endl;
        cout << "Total price: " <<orderSer.getPrice(order) << endl;
        if(order.getPaymentStatus()) {
            cout << "Payment status: Payed" << endl;
        } else {
            cout << "Payment status: Payed at delivery" << endl;
        }
    } else {
        cout << "Pickup at: " << locList[order.getLocationId() - 1].getAddress() << endl;
        cout << "Name or phone: " << order.getAddress() << endl;
        cout << "Total price: " <<orderSer.getPrice(order) << endl;
        if(order.getPaymentStatus()) {
            cout << "Payment status: Payed" << endl;
        } else {
            cout << "Payment status: Payed at delivery" << endl;
        }
    }
    if(order.getComment() != "") {
        cout << "Comment: " << order.getComment() << endl;
    }

}

void SalesUI::displayPizzaMenu() {
    Pizza* pizzaList = dataBase.pizzaMaster;
    if(pizzaList != 0) {
        cout << "Pizzas menu: " << endl;
        for (int i = 0; i < orderSer.repo.getPizzaLines(); i++) {
            if(pizzaList[i].getActiveState()) {
                cout << pizzaList[i].getIdNumber();
                cout << ")\t" << /* setw(pizzaList[0].MAX_PIZZA_LENGTH) << left << */ pizzaList[i].getName();
                cout << " | " << /* setw(pizzaList[0].getSize().MAX_STRING_LENGTH) << left << */ pizzaList[i].getSize().getName();
                cout << " | " << /* setw(pizzaList[0].getType().MAX_STRING_LENGTH) << left << */ pizzaList[i].getType().getName() + " base";
                cout << " | " << /* setw(pizzaList[0].getSauce().MAX_STRING_LENGTH) << left << */ pizzaList[i].getSauce().getName() + " sauce" << endl;
                cout << "\t " << "Toppings: ";
                for(int j = 0; j < pizzaList[0].MAX_TOPPINGS_PIZZA; j++) {
                    if(pizzaList[i].getToppings()[j].getIdNumber() != 0) {
                        cout << pizzaList[i].getToppings()[j].getName() << ", ";
                    }
                }
                cout << endl;
            }
        }
    }
}

void SalesUI::displaySizeList() {
    PizzaSize* sizeList = dataBase.sizeMaster;
    int length = dataBase.getSizeID();
    for(int i = 0; i < length; i++) {
        cout << sizeList[i].getIdNumber() << ")\t"
             << setw(24) << left << sizeList[i].getName() << "\t"
             << sizeList[i].getPriceCategory() << endl;
    }
    cout << endl;
}

void SalesUI::displayTypeList() {
    PizzaType* typeList = dataBase.typeMaster;
    int length = dataBase.getTypeID();
    for(int i = 0; i < length; i++) {
        cout << typeList[i].getIdNumber() << ")\t"
             << setw(24) << left << typeList[i].getName() << "\t"
             << typeList[i].getPriceOffset() << endl;
    }
    cout << endl;
}

void SalesUI::displaySauceList() {
    PizzaSauce* sauceList = dataBase.sauceMaster;
    int length = dataBase.getSauceID();
    for(int i = 0; i < length; i++) {
        cout << sauceList[i].getIdNumber() << ")\t"
             << setw(24) << left << sauceList[i].getName() << "\t"
             << sauceList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displayToppingList() {
    Topping* toppingList = dataBase.toppingMaster;
    int length = dataBase.getToppingID();
    for(int i = 0; i < length; i++) {
        cout << toppingList[i].getIdNumber() << ")\t"
             << setw(24) << left << toppingList[i].getName() << "\t"
             << toppingList[i].getPriceCategory() << endl;
    }
}

void SalesUI::displayExtraList() {
    Extra* extraList = dataBase.extraMaster;
    int length = dataBase.getExtraID();
    for(int i = 0; i < length; i++) {
        cout << extraList[i].getIdNumber() << ")\t"
             << setw(24) << left << extraList[i].getName() << "\t"
             << extraList[i].getPriceCategory() << endl;
    }
    cout << endl;
}

void SalesUI::displayLocationList() {
    Location* locList = dataBase.locationMaster;
    int length = dataBase.getLocationID();
    for(int i = 0; i < length; i++) {
        cout << locList[i].getIdNumber() << ")\t"
             << setw(locList[0].MAX_STRING_LENGTH) << left << locList[i].getName() << " | "
             << setw(locList[0].MAX_ADDRESS_LENGTH) << left << locList[i].getAddress() << endl;
    }
    cout << endl;
}
