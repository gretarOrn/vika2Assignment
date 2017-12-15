#include "SalesUI.h"

SalesUI::SalesUI()
{
    //ctor
}

void SalesUI::startUp() {
    system("CLS");
    int locationId;
    bool valid = false;
    do {
        displayLocationList();
        cout << "Select location: ";
        cin >> locationId;
        validate.isInt(locationId);
        try {
            validate.validateLocation(locationId, valid);
        }
        catch(InvalidLocationException) {
            cout <<"Invalid location input." << endl;
        }
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
            int lines = orderSer.repo.getActiveOrderLines();
            int index;
            cout << "Lines: " << lines << endl;
            for(int i = 0; i < lines; i++) {
                displayOrder(orderList[i]);
                cout << endl;
            }

            cout << "Select order to move to inactive: ";
            cin >> index;
            orderSer.moveOrderToInactiveFile(index - 1);
            lines = orderSer.repo.getActiveOrderLines();
            orderList = dataBase.activeOrderMaster;
            cout << "*********************************************************************" << endl;
            cout << "Lines: " << lines << endl;
            for(int i = 0; i < lines; i++) {
                displayOrder(orderList[i]);
                cout << endl;
            }
        } else if(c == '3') {
            Order* inactiveOrderList = dataBase.inactiveOrderMaster;
            cout << orderSer.repo.getInactiveOrderLines() << endl;
            for(int i = 0; i < orderSer.repo.getInactiveOrderLines(); i++) {
                displayOrder(inactiveOrderList[i]);
                cout << endl;
            }
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
    bool valid = false;
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
            validate.isInt(input);
            try {
                validate.validatePizzaSelection(input,valid);
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
    int pizzaCounter;
    int toppingCounter;
    int sizeSelection;
    int typeSelection;
    int sauceSelection;
    int toppingSelection[order.getPizzas()[0].MAX_TOPPINGS_PIZZA];
    Pizza pizza;
    bool valid = false;

    char userInput;
    //int input;
    do {
        system("CLS");
        pizzaCounter = 0;
        cout << "Pizzas in current order: " << endl;
        for(int i = 0; i < order.MAX_PIZZAS_ORDER; i++) {
                if(order.getPizzas()[i].getName() != "") {
                    cout << (i + 1) << ")  " << order.getPizzas()[i].getName() << endl;
                    pizzaCounter++;
                } else if(order.getPizzas()[i].getSauce().getIdNumber() != 0) {
                    cout << (i + 1) << ")  Custom pizza" << endl;
                    pizzaCounter++;
                }
        }
        cout << "----------------------------------------------------------------" << endl << endl;

        displaySizeList();
        do{
            cout << "Select size: ";
            cin >> sizeSelection;
            validate.isInt(sizeSelection);
            try {
                validate.validateSizeSelection(sizeSelection, valid);
            }
            catch (InvalidSizeException) {
                cout <<"Invalid size selection." << endl;
            }

            cout << endl;
        }while(!valid);

        valid = false;
        displayTypeList();
        do{
            cout << "Select type: ";
            cin >> typeSelection;
            validate.isInt(typeSelection);
            try {
                validate.validateTypeSelection(typeSelection, valid);
            }
            catch(InvalidTypeException) {
                cout <<"Invalid type selection." << endl;
            }
            cout << endl;
        }while(!valid);

        valid = false;
        displaySauceList();
        do{
            cout << "Select sauce: ";
            cin >> sauceSelection;
            validate.isInt(sauceSelection);
            try {
                validate.validateSauceSelection(sauceSelection, valid);
            }
            catch(InvalidSauceException) {
                cout << "Invalid sauce input." << endl;
            }
            cout << endl;
        }while(!valid);

        displayToppingList();
        cout << "Select toppings (type 0 to stop)" << endl;
        toppingCounter = 0;
        //int arr[dataBase.pizzaMaster[0].MAX_TOPPINGS_PIZZA];
        while(toppingCounter < dataBase.pizzaMaster[0].MAX_TOPPINGS_PIZZA) {
            valid = false;
            do {
                cin >> toppingSelection[toppingCounter];
                validate.isInt(toppingSelection[toppingCounter]);
                try{
                    validate.validateToppingSelection(toppingSelection[toppingCounter], valid);
                }
                catch(InvalidToppingException) {
                    cout <<"Invalid topping selection." << endl;
                }


            }while(!valid);


            if(toppingSelection[toppingCounter] == 0) {
                    toppingCounter++;
                break;
            }
            toppingCounter++;
        }
        pizza = pizzaSer.createPizza(sizeSelection, typeSelection, sauceSelection, toppingSelection);
        printPizza(pizza, toppingCounter);

        cout << endl;
        cout << "Confirm pizza? (y/n) ";
        cin >> userInput;
        if(userInput == 'y') {
            order.getPizzas()[pizzaCounter] = pizza;

            /*
            order.getPizzas()[pizzaCounter].setSize(pizzaSer.addSize(sizeSelection));
            order.getPizzas()[pizzaCounter].setType(pizzaSer.addType(typeSelection));
            order.getPizzas()[pizzaCounter].setSauce(pizzaSer.addSauce(sauceSelection));
            order.getPizzas()[pizzaCounter].addToppings(pizzaSer.addTopping(toppingSelection, order.getPizzas()[pizzaCounter]));
            */
            //pizzaSer.addPizzaToOrder(order.getPizzas()[i], dataBase.toppingMaster[toppingSelection[j]]);

            pizzaCounter++;
        }

        cout << endl;
        cout << "Add another pizza to order? (y/n) ";
        cin >> userInput;
    } while (userInput == 'y');

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
    bool valid = false;
    for (int i = 0; i < order.MAX_EXTRAS_ORDER; i++) {
        printExtra(order);
        cout << "----------------------------------------------------------------" << endl << endl;
        displayExtraList();
        do{
            cout << "Select extra: ";
            cin >> input;
            validate.isInt(input);
            try{
                validate.validateExtraSelection(input, valid);
            }
            catch(InvalidExtraException) {
                cout <<"Invalid extra selection." << endl;
            }
        }while(!valid);

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
    bool valid = true;
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
                validate.validateName(address, valid);
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
            validate.isInt(userSelection);
            try{
                validate.validateLocation(userSelection, valid);
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
        cout << "Order saved" << endl;
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
        cout << "Special: " << order.getName() << endl;
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
                cout << ")\t" << /* setw(pizzaList[0].MAX_PIZZA_LENGTH) << left << */ pizzaList[i].getName() << endl;
                cout << "\t  " << /* setw(pizzaList[0].getSize().MAX_STRING_LENGTH) << left << */ setw(9) << pizzaList[i].getSize().getName();
                cout << " | " << /* setw(pizzaList[0].getType().MAX_STRING_LENGTH) << left << */ pizzaList[i].getType().getName() + " base";
                cout << " | " << /* setw(pizzaList[0].getSauce().MAX_STRING_LENGTH) << left << */ pizzaList[i].getSauce().getName() + " sauce" << endl;
                cout << "\t  " << "Toppings: ";
                for(int j = 0; j < pizzaList[0].MAX_TOPPINGS_PIZZA; j++) {
                    if(pizzaList[i].getToppings()[j].getIdNumber() != 0) {
                        cout << pizzaList[i].getToppings()[j].getName() << ", ";
                    }
                }
                cout << "\n\t  " << "Price: " << pizzaSer.getPrice(pizzaList[i]) << "kr" << endl;
            }
        }
    }
}

void SalesUI::displaySizeList() {
    PizzaSize* sizeList = dataBase.sizeMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(sizeList != 0) {
        cout << "Sizes in current list: " << endl;
        for (int i = 0; i < orderSer.repo.getSizeLines(); i++) {
            if(sizeList[i].getActiveState()) {
                cout << sizeList[i].getIdNumber();
                cout << ")\t" << setw(sizeList[0].MAX_STRING_LENGTH) << left << sizeList[i].getName();
                cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[sizeList[i].getPriceCategory()-1].getName();
                cout << " | " << setw(4) << right << priceList[sizeList[i].getPriceCategory()-1].getPrice() << "kr | ";
                cout << endl;
            }
        }
    }
}

void SalesUI::displayTypeList() {
    PizzaType* typeList = dataBase.typeMaster;
    if(typeList != 0) {
        cout << "Bases in current list: " << endl;
        for (int i = 0; i < orderSer.repo.getTypeLines(); i++) {
            if(typeList[i].getActiveState()) {
                cout << typeList[i].getIdNumber();
                cout << ")\t" << setw(typeList[0].MAX_STRING_LENGTH) << left << typeList[i].getName();
                cout << " | " << setw(4) << right << typeList[i].getPriceOffset() << "kr | ";
                cout << endl;
            }
        }
    }
}

void SalesUI::displaySauceList() {
    PizzaSauce* sauceList = dataBase.sauceMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(sauceList != 0) {
        cout << "Sauces in current list: " << endl;
        for (int i = 0; i < orderSer.repo.getSauceLines(); i++) {
            if(sauceList[i].getActiveState()) {
                cout << sauceList[i].getIdNumber();
                cout << ")\t" << setw(sauceList[0].MAX_STRING_LENGTH) << left << sauceList[i].getName();
                cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[sauceList[i].getPriceCategory()-1].getName();
                cout << " | " << setw(4) << right << priceList[sauceList[i].getPriceCategory()-1].getPrice() << "kr | ";
                cout << endl;
            }
        }
    }
}

void SalesUI::displayToppingList() {
    Topping* toppingList = dataBase.toppingMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(toppingList != 0) {
        cout << "Toppings in current list: " << endl;
        for (int i = 0; i < orderSer.repo.getToppingLines(); i++) {
            if(toppingList[i].getActiveState()) {
                cout << toppingList[i].getIdNumber();
                cout << ")\t" << setw(toppingList[0].MAX_STRING_LENGTH) << left << toppingList[i].getName();
                cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[toppingList[i].getPriceCategory()-1].getName();
                cout << " | " << setw(4) << right << (priceList[toppingList[i].getPriceCategory()-1].getPrice() * dataBase.sizeMaster[0].getToppingMult()) + dataBase.sizeMaster[0].getToppingOffset() << "kr | ";
                cout << endl;
            }
        }
    }
}

void SalesUI::displayExtraList() {
    Extra* extraList = dataBase.extraMaster;
    PriceList* priceList = dataBase.priceMaster;
    if(extraList != 0) {
        cout << "Extras in current list: " << endl;
        for (int i = 0; i < orderSer.repo.getExtraLines(); i++) {
            if(extraList[i].getActiveState()) {
                cout << extraList[i].getIdNumber();
                cout << ")\t" << setw(extraList[0].MAX_STRING_LENGTH) << left << extraList[i].getName();
                cout << " | " << setw(priceList[0].MAX_STRING_LENGTH) << left << priceList[extraList[i].getPriceCategory()-1].getName();
                cout << " | " << setw(4) << right << priceList[extraList[i].getPriceCategory()-1].getPrice() << "kr | ";
                cout << endl;
            }
        }
    }
}

void SalesUI::displayLocationList() {
    Location* locList = dataBase.locationMaster;
    if(locList != 0) {
        cout << "Locations in current list: " << endl;
        for (int i = 0; i < orderSer.repo.getLocationLines(); i++) {
            if(locList[i].getActiveState()) {
                cout << locList[i].getIdNumber();
                cout << ")\t" << setw(locList[0].MAX_STRING_LENGTH) << left << locList[i].getName();
                cout << " | " << setw(locList[0].MAX_ADDRESS_LENGTH) << left << locList[i].getAddress();
                cout << " | ";
                cout << endl;
            }
        }
    }
}
